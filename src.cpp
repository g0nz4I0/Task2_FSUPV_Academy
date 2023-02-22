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
	AS_OFF* ao = new AS_OFF();
	AS_FINISHED* af = new AS_FINISHED();
	AS_EMERGENCY* ae = new AS_EMERGENCY();
	AS_READY* ar = new AS_READY();
	AS_DRIVING* ad = new AS_DRIVING();
	ae->add_Action(e);
	af->add_Action(f);
	ad->add_Action(d);
	ar->add_Action(p);
	ao->add_Action(o);
	ao->add_Action(a);
	
	while(true){
		if(current_state->EBS_Activated()){
			if(current_state->MissionFinished()){
				current_state = af;
			}else{
				current_state = ae;
			}
		}else if(current_state->MissionSelected_ChecksActive()){
			if(current_state->Ready_To_Drive()){
				current_state = ad;
			}else{
				if(current_state->Brakes_Engaged()){
					current_state = ar;
				}else{
					current_state = ao;
				}
			}
		}else{
			current_state = ao;
		}

		current_state->update();
		i = rand() % 50;
		std::this_thread::sleep_for(1000ms);

	}

}