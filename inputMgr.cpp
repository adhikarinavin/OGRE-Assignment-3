#include "inputMgr.h"
#include "engine.h"
#include <OgreFrameListener.h>
#include <OgreWindowEventUtilities.h>
#include "OgreRenderWindow.h"

InputMgr::InputMgr(Engine *eng) : Mgr(eng) {

}

InputMgr::~InputMgr() {

}

void InputMgr::init() {
    Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
    OIS::ParamList pl;
    size_t windowHnd = 0;
    std::ostringstream windowHndStr;
    engine->gfxMgr->mWindow->getCustomAttribute("WINDOW", &windowHnd);
    windowHndStr << windowHnd;
    pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
    mInputManager = OIS::InputManager::createInputSystem(pl);
    mKeyboard = static_cast<OIS::Keyboard *>(mInputManager->createInputObject(OIS::OISKeyboard, false));
    mMouse = static_cast<OIS::Mouse *>(mInputManager->createInputObject(OIS::OISMouse, false));
    mMouse->setEventCallback(this);
    mKeyboard->setEventCallback(this);
    windowResized(engine->gfxMgr->mWindow);
    Ogre::WindowEventUtilities::addWindowEventListener(engine->gfxMgr->mWindow, this);
    engine->gfxMgr->mRoot->addFrameListener(this);
}

void InputMgr::tick(float dt) {
    if (engine->gfxMgr->mWindow->isClosed()) {
        engine->keepRunning = false;
    }
}

void InputMgr::loadLevel() {


}

void InputMgr::stop() {
//Remove ourself as a Window listener
    Ogre::WindowEventUtilities::removeWindowEventListener(engine->gfxMgr->mWindow, this);
    windowClosed(engine->gfxMgr->mWindow);


}

bool InputMgr::frameRenderingQueued(const Ogre::FrameEvent &evt) {

    if (engine->gfxMgr->mWindow->isClosed()) {
        engine->keepRunning = false;
        return false;
    }
    //Need to capture/update each device
    mKeyboard->capture();
    mMouse->capture();

    if (mKeyboard->isKeyDown(OIS::KC_ESCAPE)) {
        engine->keepRunning = false;
        return false;
    }

    if (!processUnbufferedInput(evt))
        return false;


    return true;
}

bool InputMgr::keyPressed(const OIS::KeyEvent &ke) {
    std::cout << "Key Pressed: " << ke.key << std::endl;
    return true;
}

bool InputMgr::keyReleased(const OIS::KeyEvent &ke) {
    switch (ke.key)
  {
    case OIS::KC_TAB:
       engine->entityMgr->SelectNextEntity();
       break;
    default:
       break;
   }
    return true;
}


bool InputMgr::mouseMoved(const OIS::MouseEvent &me) {
    std::cout << "mouse moved" << std::endl;
    return true;
}

bool InputMgr::mousePressed(
        const OIS::MouseEvent &me, OIS::MouseButtonID id) {
    return true;
}

bool InputMgr::mouseReleased(
        const OIS::MouseEvent &me, OIS::MouseButtonID id) {
    return true;
}


bool InputMgr::processUnbufferedInput(const Ogre::FrameEvent &fe) {
    static float rad1=0;
    static float rad2=0;
    static float rad3=0;
    static float rad4=0;
    static float radc1=0;
    static float radc2=0;
    bool currenttabl = mKeyboard->isKeyDown(OIS::KC_TAB);
    if (!tabpreviousframe && currenttabl) {
        engine->entityMgr->SelectNextEntity();
    }
   tabpreviousframe = currenttabl;
   if (mKeyboard->isKeyDown(OIS::KC_NUMPAD8))
    {
       if(engine->gameMgr->entity1->isSelected)
       {
          if(engine->gameMgr->entity1->desiredSpeed<=engine->gameMgr->entity1->maxSpeed)
          {
            engine->gameMgr->entity1->desiredSpeed+=1;
          }
       }

       if(engine->gameMgr->entity2->isSelected)
       {
          if(engine->gameMgr->entity2->desiredSpeed<=engine->gameMgr->entity2->maxSpeed)
          {
            engine->gameMgr->entity2->desiredSpeed+=1;
          }
       }
       if(engine->gameMgr->entity3->isSelected)
       {
          if(engine->gameMgr->entity3->desiredSpeed<=engine->gameMgr->entity3->maxSpeed)
          {
            engine->gameMgr->entity3->desiredSpeed+=1;
          }
       }
       if(engine->gameMgr->entity4->isSelected)
       {
          if(engine->gameMgr->entity4->desiredSpeed<=engine->gameMgr->entity4->maxSpeed)
          {
            engine->gameMgr->entity4->desiredSpeed+=1;
          }
       }
       if(engine->gameMgr->entity5->isSelected)
       {
          if(engine->gameMgr->entity5->desiredSpeed<=engine->gameMgr->entity5->maxSpeed)
          {
            engine->gameMgr->entity5->desiredSpeed+=1;
          }
       }

    }
      if (mKeyboard->isKeyDown(OIS::KC_NUMPAD2))
    {
       if(engine->gameMgr->entity1->isSelected)
       {
          if(engine->gameMgr->entity1->desiredSpeed>engine->gameMgr->entity1->minSpeed)
          {
            engine->gameMgr->entity1->desiredSpeed-=1;
          }
       }

       if(engine->gameMgr->entity2->isSelected)
       {
          if(engine->gameMgr->entity2->desiredSpeed>engine->gameMgr->entity2->minSpeed)
          {
            engine->gameMgr->entity2->desiredSpeed-=1;
          }
       }
       if(engine->gameMgr->entity3->isSelected)
       {
          if(engine->gameMgr->entity3->desiredSpeed>engine->gameMgr->entity3->minSpeed)
          {
            engine->gameMgr->entity3->desiredSpeed-=1;
          }
       }
       if(engine->gameMgr->entity4->isSelected)
       {
          if(engine->gameMgr->entity4->desiredSpeed>engine->gameMgr->entity4->minSpeed)
          {
            engine->gameMgr->entity4->desiredSpeed-=1;
          }
       }
       if(engine->gameMgr->entity5->isSelected)
       {
         if(engine->gameMgr->entity5->desiredSpeed>engine->gameMgr->entity5->minSpeed)
          {
            engine->gameMgr->entity5->desiredSpeed-=1;
          }
       }

    }
     if (mKeyboard->isKeyDown(OIS::KC_NUMPAD6))
    {
        if(engine->gameMgr->entity1->isSelected)
       {
          engine->gameMgr->entity1->desiredHeading +=.01;
       }
        if(engine->gameMgr->entity2->isSelected)
       {
          engine->gameMgr->entity2->desiredHeading +=.01;
       }
        if(engine->gameMgr->entity3->isSelected)
       {
          engine->gameMgr->entity3->desiredHeading +=.01;
       }
        if(engine->gameMgr->entity4->isSelected)
       {
          engine->gameMgr->entity4->desiredHeading +=.01;
       }
        if(engine->gameMgr->entity5->isSelected)
       {
          engine->gameMgr->entity5->desiredHeading +=.01;
       }

     }
      if (mKeyboard->isKeyDown(OIS::KC_NUMPAD4))
    {
        if(engine->gameMgr->entity1->isSelected)
       {
          engine->gameMgr->entity1->desiredHeading -=.01;
       }
        if(engine->gameMgr->entity2->isSelected)
       {
          engine->gameMgr->entity2->desiredHeading -=.01;
       }
        if(engine->gameMgr->entity3->isSelected)
       {
          engine->gameMgr->entity3->desiredHeading -=.01;
       }
        if(engine->gameMgr->entity4->isSelected)
       {
          engine->gameMgr->entity4->desiredHeading -=.01;
       }
        if(engine->gameMgr->entity5->isSelected)
       {
          engine->gameMgr->entity5->desiredHeading -=.01;
       }

     }
      Ogre::Vector3 cdirVec = engine->gfxMgr->mCamera->getPosition();
    if (mKeyboard->isKeyDown(OIS::KC_R))
        cdirVec.y += 50 * fe.timeSinceLastFrame;

    if (mKeyboard->isKeyDown(OIS::KC_F))
        cdirVec.y -= 50 * fe.timeSinceLastFrame;
    if (mKeyboard->isKeyDown(OIS::KC_S))
        cdirVec.z += 50 * fe.timeSinceLastFrame;

    if (mKeyboard->isKeyDown(OIS::KC_W))
        cdirVec.z -= 50 * fe.timeSinceLastFrame;
    if (mKeyboard->isKeyDown(OIS::KC_D))
        cdirVec.x += 50 * fe.timeSinceLastFrame;

    if (mKeyboard->isKeyDown(OIS::KC_A))
        cdirVec.x -= 50 * fe.timeSinceLastFrame;
    if(mKeyboard->isKeyDown(OIS::KC_E))
    {
       rad1+=.001;
       rad2=-rad1;
       radc2=-rad1;
       engine->gfxMgr->mCamera->setOrientation(Ogre::Quaternion::IDENTITY);
       engine->gfxMgr->mCamera->yaw(Ogre::Radian(-rad1));
       engine->gfxMgr->mCamera->pitch(Ogre::Radian(radc1));


    }
    if(mKeyboard->isKeyDown(OIS::KC_Q))
    {
       rad2+=.001;
       rad1=-rad2;
       radc2=rad2;
       engine->gfxMgr->mCamera->setOrientation(Ogre::Quaternion::IDENTITY);
       engine->gfxMgr->mCamera->yaw(Ogre::Radian(rad2));
       engine->gfxMgr->mCamera->pitch(Ogre::Radian(radc1));


    }
     if(mKeyboard->isKeyDown(OIS::KC_X))
    {
       rad3+=.001;
       rad4=-rad3;
       radc1=-rad3;
       engine->gfxMgr->mCamera->setOrientation(Ogre::Quaternion::IDENTITY);
       engine->gfxMgr->mCamera->pitch(Ogre::Radian(-rad3));
       engine->gfxMgr->mCamera->yaw(Ogre::Radian(radc2));

    }
    if(mKeyboard->isKeyDown(OIS::KC_Z))
    {
       rad4+=.001;
       rad3=-rad4;
       radc1=rad4;
       engine->gfxMgr->mCamera->setOrientation(Ogre::Quaternion::IDENTITY);
       engine->gfxMgr->mCamera->pitch(Ogre::Radian(rad4));
       engine->gfxMgr->mCamera->yaw(Ogre::Radian(radc2));

    }
    engine->gfxMgr->mCamera->setPosition(cdirVec);

    return true;
}


//Adjust mouse clipping area
void InputMgr::windowResized(Ogre::RenderWindow *rw) {
    unsigned int width, height, depth;
    int left, top;
    rw->getMetrics(width, height, depth, left, top);

    const OIS::MouseState &ms = mMouse->getMouseState();
    ms.width = width;
    ms.height = height;
}

//Unattach OIS before window shutdown (very important under Linux)
void InputMgr::windowClosed(Ogre::RenderWindow *rw) {
    //Only close for window that created OIS (the main window in these demos)
    if (rw == engine->gfxMgr->mWindow) {
        if (mInputManager) {
            mInputManager->destroyInputObject(mMouse);
            mInputManager->destroyInputObject(mKeyboard);

            OIS::InputManager::destroyInputSystem(mInputManager);
            mInputManager = 0;
        }
    }
}
