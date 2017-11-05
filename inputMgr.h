#ifndef INPUTMGR_H
#define INPUTMGR_H

#include "engine.h"
#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>
#include <OgreWindowEventUtilities.h>
#include "mgr.h"


class Engine;
class InputMgr : public Mgr, public Ogre::WindowEventListener, public Ogre::FrameListener,public OIS::KeyListener, public OIS::MouseListener {
    OIS::InputManager *mInputManager;
    OIS::Mouse *mMouse;
    OIS::Keyboard *mKeyboard;

    bool tabpreviousframe = false;
    Ogre::Real toggleTimer = 0.0;
public:
    InputMgr(Engine *eng);

    ~InputMgr();

    virtual void init();

    virtual void tick(float dt);

    virtual void loadLevel();

    virtual void stop();

    virtual void windowResized(Ogre::RenderWindow *rw);

    virtual void windowClosed(Ogre::RenderWindow *rw);

    virtual bool keyPressed(const OIS::KeyEvent& ke);
    virtual bool keyReleased(const OIS::KeyEvent& ke);
    virtual bool mouseMoved(const OIS::MouseEvent& me);
    virtual bool mousePressed(const OIS::MouseEvent& me, OIS::MouseButtonID id);
    virtual bool mouseReleased(const OIS::MouseEvent& me, OIS::MouseButtonID id);

    // Ogre::FrameListener
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
    bool processUnbufferedInput(const Ogre::FrameEvent& evt);
    void selectNext();

};

#endif //INPUTMGR_H
