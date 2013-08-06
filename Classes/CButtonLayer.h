#ifndef __BUTTON_SCENE_H__
#define __BUTTON_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h" 
#include "COperateScene.h"
#include <list>
#include "CWell.h"


using namespace cocos2d;
USING_NS_CC_EXT;  

class CCButtonLayer : public cocos2d::CCLayer
{
public:
	CCButtonLayer(void);
	~CCButtonLayer(void);
public:
	CCSprite * m_pLead; //主角精灵
	cocos2d::CCMoveBy *m_pMove;
	CCOperateScene * pGameLayer;
	int dirTag; //移动方向
	int m_pTagWell; //触碰到墙体
	static const int MoveLength = 2; //移动量
	enum direction{
		kUp,
		kDown,
		kLeft,
		kRight
	};

	enum m_pEnumWell{
		kyellow,
		kred,
		kgreen,
		kblue
	};



	CCWell * m_pWell;
	CCArray * arrWell;

	struct struct_wall
	{
		list<CCPoint> yellow_wall;
		list<CCPoint> red_wall;
		list<CCPoint> green_wall;
		list<CCPoint> blue_wall;
	};

	struct_wall scene1_wall;

public:
	virtual bool init();
	static CCButtonLayer * create();

	//按钮事件回调函数
	void touchDragInsideUp(CCObject* pSender, CCControlEvent event);
	void touchDragInsideDown(CCObject* pSender, CCControlEvent event);
	void touchDragInsideLeft(CCObject* pSender, CCControlEvent event);	
	void touchDragInsideRight(CCObject* pSender, CCControlEvent event);

	void touchDragInsideUp2(CCObject* pSender, CCControlEvent event);
	void touchDragInsideDown2(CCObject* pSender, CCControlEvent event);
	void touchDragInsideLeft2(CCObject* pSender, CCControlEvent event);	
	void touchDragInsideRight2(CCObject* pSender, CCControlEvent event);

	bool update(CCRect leadRect); //检测碰撞

	/************************************************************************/
	/* 精灵移动 开始                                                                    */
	/************************************************************************/
	void MoveHeroBegin(float t);
	/************************************************************************/
	/* 精灵移动 停止                                                                     */
	/************************************************************************/
	void MoveHeroEnd();
	/************************************************************************/
	/* 墙体消失                                                                     */
	/************************************************************************/
	void callNodeBack(CCNode *sender);

	list<CCPoint> initList(int arr[][2],int n);

};

#endif