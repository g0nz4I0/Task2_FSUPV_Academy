#include<thread>
#include<chrono>
#include<cstdlib>

#include "statemachine.hpp"
using namespace std::chrono;
extern int i;
Action a = [](){
	std::cout<<"\n\tsecond action";
};
Action e = [](){
	std::cout<<"\n!!!AS_EMERGENCY!!!";
};
Action f = [](){
	std::cout<<"\n----------------------\nMISSION FINISHED\n----------------------";
};

Action d = [](){
	std::cout<<"\n...\ndriving\n...";
};

Action p = [](){
	std::cout<<"\n----------------------\nREADY\n----------------------";
};

Action o = [](){
	std::cout<<"\nOFF";
};

int main(){
	State* current_state = new State();
	State* ao = new State();
	State* af = new State();
	State* ae = new State();
	State* ar = new State();
	State* ad = new State();
	ae->add_Action(e);
	af->add_Action(f);
	ad->add_Action(d);
	ar->add_Action(p);
	ao->add_Action(o);
	ao->add_Action(a);
	
	while(true){
		if(EBS_Activated()){
			if(MissionFinished()){
				current_state = af;
			}else{
				current_state = ae;
			}
		}else if(MissionSelected_ChecksActive()){
			if(Ready_To_Drive()){
				current_state = ad;
			}else{
				if(Brakes_Engaged()){
					current_state = ar;
				}else{
					current_state = ao;
				}
			}
		}else{
			current_state = ao;
		}
		current_state->update();
	}
}
