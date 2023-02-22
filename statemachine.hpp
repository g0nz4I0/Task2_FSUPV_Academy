//state machine implementation fsupv academy
//feb2023
//@g0nz4i0


#include<iostream>
#include<vector>
#include<functional>
#include<string>


typedef std::function<void()> Action;

	//we can define mock functions to match the name in the rulebook
bool EBS_Activated();// could be used as a facade 
bool MissionFinished();
bool MissionSelected_ChecksActive();
bool Ready_To_Drive();
bool Brakes_Engaged();

struct State
{
	//////////////////////////////
	std::vector<Action> actions{};
	void add_Action(Action a);
	void update();

};
struct AS_OFF : State{
};
struct AS_EMERGENCY : State{

};
struct AS_FINISHED : State{
};
struct AS_READY : State{
};
struct AS_DRIVING : State{
};
