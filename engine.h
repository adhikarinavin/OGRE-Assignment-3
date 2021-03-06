#ifndef ENGINE_H_
#define ENGINE_H_
#include "GfxMgr.h"
#include "inputMgr.h"
#include "EntityMgr.h"
#include "gameMgr.h"
class GameMgr;
class GfxMgr;
class InputMgr;
class EntityMgr;
class Engine
{
private:
public:
	Engine();
	~Engine();
	EntityMgr* entityMgr;
    GfxMgr* gfxMgr;
	InputMgr* inputMgr;
	GameMgr* gameMgr;
	//SelectionMgr* selectionMgr;
	//ControlMgr*   controlMgr;

	void init();
	void run();
	void tickAll(float dt);
	void stop();
	void shutdown();

	//
	bool keepRunning;


};

#endif /* ENGINE_H_ */
