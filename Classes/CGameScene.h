#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "COperateScene.h"
#include "CButtonLayer.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
using namespace std;
class CCGameScene : cocos2d::CCLayer
{
public:
	CCGameScene(void);
	~CCGameScene(void);
public:
	CCSprite* m_pBackground; //游戏背景
	CCSprite * m_pLead;//主角
	CCOperateScene * m_pGameLayer; //游戏层
	CCButtonLayer * m_pButton; //按钮层


	



public:
	virtual bool init(); //初始化函数

	static cocos2d::CCScene* scene(); //场景加载

	CREATE_FUNC(CCGameScene);

    void menuCloseCallback(CCObject* pSender);//退出菜单回调函数

	/************************************************************************/
	/* 初始化墙体集合                                                                     */
	/************************************************************************/
	list<CCPoint> initList(int arr[][2],int n);
};

#endif
