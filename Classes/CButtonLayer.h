#ifndef __BUTTON_SCENE_H__
#define __BUTTON_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h" 
#include "COperateScene.h"

using namespace cocos2d;
USING_NS_CC_EXT;  

class CCButtonLayer : public cocos2d::CCLayer
{
public:
	CCButtonLayer(void);
	~CCButtonLayer(void);
public:
	CCSprite * m_pLead; //���Ǿ���
	cocos2d::CCMoveBy *m_pMove;
	CCOperateScene * pGameLayer;
	int dirTag; //�ƶ�����
	enum direction{
		kUp,
		kDown,
		kLeft,
		kRight
	};

public:
	virtual bool init();
	static CCButtonLayer * create();

	//��ť�¼��ص�����
	void touchDragInsideUp(CCObject* pSender, CCControlEvent event);
	void touchDragInsideDown(CCObject* pSender, CCControlEvent event);
	void touchDragInsideLeft(CCObject* pSender, CCControlEvent event);	
	void touchDragInsideRight(CCObject* pSender, CCControlEvent event);

	void touchDragInsideUp2(CCObject* pSender, CCControlEvent event);
	void touchDragInsideDown2(CCObject* pSender, CCControlEvent event);
	void touchDragInsideLeft2(CCObject* pSender, CCControlEvent event);	
	void touchDragInsideRight2(CCObject* pSender, CCControlEvent event);

	void update(float dt); //�����ײ

	/************************************************************************/
	/* �����ƶ� ��ʼ                                                                    */
	/************************************************************************/
	void MoveHeroBegin(float t);
	/************************************************************************/
	/* �����ƶ� ֹͣ                                                                     */
	/************************************************************************/
	void MoveHeroEnd(CCNode * sender);


};

#endif