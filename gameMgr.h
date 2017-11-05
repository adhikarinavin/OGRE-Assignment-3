#ifndef GAMEMGR_H
#define GAMEMGR_H


#include "mgr.h"
#include "engine.h"
#include<OgreVector3.h>
#include"Entity381.h"

class Engine;


class GameMgr : public Mgr {

public:
    GameMgr(Engine* eng);
    ~GameMgr();

    virtual void init();

    virtual void tick(float dt);

    virtual void loadLevel();

    virtual void stop();
    Ogre::Vector3 b1;
    Ogre::Vector3 b2;
    Ogre::Vector3 b3;
    Ogre::Vector3 b4;
    Ogre::Vector3 b5;
    float head;
    Entity381* entity1;
    Entity381* entity2;
    Entity381* entity3;
    Entity381* entity4;
    Entity381* entity5;


};

#endif //GAMEMGR_H
