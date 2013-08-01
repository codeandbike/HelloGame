#include "CButtonLayer.h"


CCButtonLayer::CCButtonLayer(void)
{
	m_pMove = NULL;
}


CCButtonLayer::~CCButtonLayer(void)
{
}

bool CCButtonLayer::init()
{
	bool sRet = false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		this->m_pMove = CCMoveBy::create(0,ccp(0,0));

		//加载向上按钮
		CCScale9Sprite *btnNormal = CCScale9Sprite::create("up2.png");
		CCScale9Sprite *btnSelected = CCScale9Sprite::create("up1.png");
		CCControlButton *pButtonUP = CCControlButton::create(btnNormal);
		pButtonUP->setPreferredSize(CCSizeMake(48,48));
		pButtonUP->setBackgroundSpriteForState(btnSelected,CCControlStateSelected);
		pButtonUP->setPosition(ccp(size.width/2,((150/4)*3)+12.5));
		pButtonUP->addTargetWithActionForControlEvents(this,cccontrol_selector(CCButtonLayer::touchDragInsideUp),CCControlEventTouchDown);
		pButtonUP->addTargetWithActionForControlEvents(this,cccontrol_selector(CCButtonLayer::touchDragInsideUp2),CCControlEventTouchUpInside);
		pButtonUP->addTargetWithActionForControlEvents(this,cccontrol_selector(CCButtonLayer::touchDragInsideUp2),CCControlEventTouchUpOutside);
		this->addChild(pButtonUP);

		//添加向下按钮
		btnNormal = CCScale9Sprite::create("down2.png");
		btnSelected = CCScale9Sprite::create("down1.png");
		CCControlButton *pButtonDown = CCControlButton::create(btnNormal);
		pButtonDown->setPreferredSize(CCSizeMake(48,48));
		pButtonDown->setBackgroundSpriteForState(btnSelected,CCControlStateSelected);
		pButtonDown->setPosition(ccp(size.width/2,(150/4)-12.5));
		pButtonDown->addTargetWithActionForControlEvents(this,cccontrol_selector(CCButtonLayer::touchDragInsideDown),CCControlEventTouchDown);
		pButtonDown->addTargetWithActionForControlEvents(this,cccontrol_selector(CCButtonLayer::touchDragInsideDown2),CCControlEventTouchUpInside);
		pButtonDown->addTargetWithActionForControlEvents(this,cccontrol_selector(CCButtonLayer::touchDragInsideUp2),CCControlEventTouchUpOutside);
		this->addChild(pButtonDown);

		//添加向左按钮
		btnNormal = CCScale9Sprite::create("left2.png");
		btnSelected = CCScale9Sprite::create("left1.png");
		CCControlButton *pButtonLeft = CCControlButton::create(btnNormal);
		pButtonLeft->setPreferredSize(CCSizeMake(48,48));
		pButtonLeft->setBackgroundSpriteForState(btnSelected,CCControlStateSelected);
		pButtonLeft->setPosition(ccp((size.width/2)-48,150/2));
		pButtonLeft->addTargetWithActionForControlEvents(this,cccontrol_selector(CCButtonLayer::touchDragInsideLeft),CCControlEventTouchDown);
		pButtonLeft->addTargetWithActionForControlEvents(this,cccontrol_selector(CCButtonLayer::touchDragInsideLeft2),CCControlEventTouchUpInside);
		pButtonLeft->addTargetWithActionForControlEvents(this,cccontrol_selector(CCButtonLayer::touchDragInsideUp2),CCControlEventTouchUpOutside);
		this->addChild(pButtonLeft);

		//添加向右按钮
		btnNormal = CCScale9Sprite::create("right2.png");
		btnSelected = CCScale9Sprite::create("right1.png");
		CCControlButton *pButtonRight = CCControlButton::create(btnNormal);
		pButtonRight->setPreferredSize(CCSizeMake(48,48));
		pButtonRight->setBackgroundSpriteForState(btnSelected,CCControlStateSelected);
		pButtonRight->setPosition(ccp((size.width/2)+48,150/2));
		pButtonRight->addTargetWithActionForControlEvents(this,cccontrol_selector(CCButtonLayer::touchDragInsideRight),CCControlEventTouchDown);
		pButtonRight->addTargetWithActionForControlEvents(this,cccontrol_selector(CCButtonLayer::touchDragInsideRight2),CCControlEventTouchUpInside);
		pButtonRight->addTargetWithActionForControlEvents(this,cccontrol_selector(CCButtonLayer::touchDragInsideUp2),CCControlEventTouchUpOutside);
		this->addChild(pButtonRight);


		sRet = true;
	} while (0);
	return sRet;
}

CCButtonLayer *CCButtonLayer::create()
{
	CCButtonLayer *pRet = new CCButtonLayer();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}


void CCButtonLayer::touchDragInsideUp(CCObject* pSender, CCControlEvent event)
{
// 		this->schedule(schedule_selector(CCButtonLayer::update));
// 	this->m_pLead->stopAction(this->m_pMove);
// 
// 	float y = CCDirector::sharedDirector()->getWinSize().height - this->m_pLead->getPositionY();
// 	float time = (5/CCDirector::sharedDirector()->getWinSize().height)*y;
// 
// 	this->m_pMove = CCMoveBy::create(time,ccp(0,y));
// 
// 	this->m_pLead->runAction(m_pMove);
	
	dirTag = kUp;
	this->schedule(schedule_selector(CCButtonLayer::MoveHeroBegin),0.01);


}
void CCButtonLayer::touchDragInsideDown(CCObject* pSender, CCControlEvent event)
{
// 	this->schedule(schedule_selector(CCButtonLayer::update));
// 	this->m_pLead->stopAction(this->m_pMove);
// 	float y = this->m_pLead->getPositionY();
// 	float time = (5/CCDirector::sharedDirector()->getWinSize().height)*y;
// 
// 	this->m_pMove = CCMoveBy::create(time,ccp(0,0-y));
// 
// 	this->m_pLead->runAction(m_pMove);

	dirTag = kDown;
	this->schedule(schedule_selector(CCButtonLayer::MoveHeroBegin),0.01);
	
}
void CCButtonLayer::touchDragInsideLeft(CCObject* pSender, CCControlEvent event)
{
// 		this->schedule(schedule_selector(CCButtonLayer::update));
// 	this->m_pLead->stopAction(this->m_pMove);
// 	float x = this->m_pLead->getPositionX();
// 	float time = (5/CCDirector::sharedDirector()->getWinSize().height)*x;
// 
// 	this->m_pMove = CCMoveBy::create(time,ccp(0-x,0));
// 
// 	this->m_pLead->runAction(m_pMove);
	dirTag = kLeft;
	this->schedule(schedule_selector(CCButtonLayer::MoveHeroBegin),0.01);


}
void CCButtonLayer::touchDragInsideRight(CCObject* pSender, CCControlEvent event)
{
// 	this->schedule(schedule_selector(CCButtonLayer::update));
// 	this->m_pLead->stopAction(this->m_pMove);
// 	float x =  CCDirector::sharedDirector()->getWinSize().width - this->m_pLead->getPositionX();
// 	float time = (5/CCDirector::sharedDirector()->getWinSize().height)*x;
// 
// 	this->m_pMove = CCMoveBy::create(time,ccp(x,0));
// 
// 	this->m_pLead->runAction(m_pMove);
	dirTag = kRight;
	this->schedule(schedule_selector(CCButtonLayer::MoveHeroBegin),0.01);
	
}


void CCButtonLayer::touchDragInsideUp2(CCObject* pSender, CCControlEvent event)
{
// 	this->m_pLead->stopAction(this->m_pMove);
// 	this->unschedule(schedule_selector(CCButtonLayer::update));

	this->unschedule(schedule_selector(CCButtonLayer::MoveHeroBegin));

}
void CCButtonLayer::touchDragInsideDown2(CCObject* pSender, CCControlEvent event)
{

// 	this->m_pLead->stopAction(this->m_pMove);
// 	this->unschedule(schedule_selector(CCButtonLayer::update));
	this->unschedule(schedule_selector(CCButtonLayer::MoveHeroBegin));
}
void CCButtonLayer::touchDragInsideLeft2(CCObject* pSender, CCControlEvent event)
{
// 	this->m_pLead->stopAction(this->m_pMove);
// 	this->unschedule(schedule_selector(CCButtonLayer::update));
	this->unschedule(schedule_selector(CCButtonLayer::MoveHeroBegin));
}
void CCButtonLayer::touchDragInsideRight2(CCObject* pSender, CCControlEvent event)
{
// 	this->m_pLead->stopAction(this->m_pMove);
// 	this->unschedule(schedule_selector(CCButtonLayer::update));
	this->unschedule(schedule_selector(CCButtonLayer::MoveHeroBegin));
}


void CCButtonLayer::update(float dt) //检测碰撞
{
// 	CCObject* it;
// 	CCARRAY_FOREACH(this->pGameLayer->greenArray,it)
// 	{
// 		CCSprite * pWellSprite = dynamic_cast<CCSprite*>(it);
// 		CCRect wellRect = CCRectMake(pWellSprite->getPositionX()-pWellSprite->getContentSize().width/2,
// 			pWellSprite->getPositionY()-pWellSprite->getContentSize().height/2,
// 			pWellSprite->getContentSize().width,pWellSprite->getContentSize().height);
// 
// 		CCRect LeadRect = CCRectMake(m_pLead->getPositionX()-2.5f,m_pLead->getPositionY()-2.5f,5,5);
// 
// 		if (LeadRect.intersectsRect(wellRect))
// 		{
// 			m_pLead->stopAction(m_pMove);
// 			this->unschedule(schedule_selector(CCButtonLayer::update));
// 		}
// 
// 	}

}

/************************************************************************/
/* 精灵移动 开始                                                                    */
/************************************************************************/
void CCButtonLayer::MoveHeroBegin(float t)
{

	//检查碰撞

	//移动方块
	switch(dirTag)
	{
	case kUp:
		this->m_pLead->setPositionY(this->m_pLead->getPositionY()+2);
		break;
	case kDown:
		this->m_pLead->setPositionY(this->m_pLead->getPositionY()-2);
		break;
	case kLeft:
		this->m_pLead->setPositionX(this->m_pLead->getPositionX()-2);
		break;
	case kRight:
		this->m_pLead->setPositionX(this->m_pLead->getPositionX()+2);
		break;
	default:
		break;
	}
}

/************************************************************************/
/* 精灵移动 停止                                                                     */
/************************************************************************/
void CCButtonLayer::MoveHeroEnd(CCNode * sender)
{

}