#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "CLead.h"
#include "COperateScene.h"
#include "CButtonLayer.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
class CCGameScene : cocos2d::CCLayer
{
public:
	CCGameScene(void);
	~CCGameScene(void);
public:
	CCSprite* m_pBackground; //��Ϸ����
	CCSprite * m_pLead;//����
	CCOperateScene * m_pGameLayer; //��Ϸ��
	CCButtonLayer * m_pButton; //��ť��



public:
	virtual bool init(); //��ʼ������

	static cocos2d::CCScene* scene(); //��������

	CREATE_FUNC(CCGameScene);

    void menuCloseCallback(CCObject* pSender);//�˳��˵��ص�����
};

#endif
