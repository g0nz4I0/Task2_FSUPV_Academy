//statemachine impl file
//we use a facade pattern
//this means we wrap our functions around another functions/libraries/frameworks
//in that case if the impl of a specific function were to change 
//the naming would stay the same, and all we'd have to do is change the function that it references
//this is done to improve readability

#include "statemachine.hpp"
int i = 0;
bool State::EBS_Activated(){
	//this could call a external function
	return i%2;
}
bool State::MissionFinished(){

	return !(i%2);
}
bool State::MissionSelected_ChecksActive(){
	return i%3;
}
bool State::Ready_To_Drive(){
	return i%4;
}
bool State::Brakes_Engaged(){
	return !(i%2);
}
void State::update(){
	for(const auto e : actions){
		e();
	}
}
void State::add_Action(Action a){
	actions.push_back(a);
	return;
}


