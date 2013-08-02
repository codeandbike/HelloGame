#include "CButtonLayer.h"


CCButtonLayer::CCButtonLayer(void)
{
	m_pMove = NULL;
	m_pWell = NULL;
	arrWell = new CCArray;
}


CCButtonLayer::~CCButtonLayer(void)
{
	if (arrWell !=NULL)
	{
		arrWell->release();
		arrWell = NULL;
	}
}

bool CCButtonLayer::init()
{
	bool sRet = false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		this->m_pMove = CCMoveBy::create(0,ccp(0,0));

		//初始化墙体位置

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
	this->schedule(schedule_selector(CCButtonLayer::MoveHeroBegin),0.01f);


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
	this->schedule(schedule_selector(CCButtonLayer::MoveHeroBegin),0.01f);
	
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
	this->schedule(schedule_selector(CCButtonLayer::MoveHeroBegin),0.01f);


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
	this->schedule(schedule_selector(CCButtonLayer::MoveHeroBegin),0.01f);
	
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


bool CCButtonLayer::update(CCRect leadRect) //检测碰撞
{

	list<CCPoint>::iterator iter;
	for (iter = yellow_wall.begin();iter!=yellow_wall.end();iter++)
	{
		//list<CCPoint>::iterator iter = yellow_wall.begin()+i;
		CCPoint temp = *iter;
		CCRect wellRect = CCRectMake(temp.x-5,temp.y-5,10,10); 
		if (leadRect.intersectsRect(wellRect))
		{
			m_pTagWell = kyellow;
			return false;
		}

	}

	return true;

}

/************************************************************************/
/* 精灵移动 开始                                                                    */
/************************************************************************/
void CCButtonLayer::MoveHeroBegin(float t)
{

	//检查碰撞


	//移动方块
	CCRect leadRect;
	switch(dirTag)
	{
	
	case kUp:
		{
			//获取移动后位置
			leadRect = CCRectMake(m_pLead->getPositionX()-2.5f,m_pLead->getPositionY()-2.5f+MoveLength,5,5);
			if (update(leadRect))
			{
				this->m_pLead->setPositionY(this->m_pLead->getPositionY()+MoveLength);
			}else
			{

				MoveHeroEnd();
			}
			break;
		}
	case kDown:
		//获取移动后位置
		leadRect = CCRectMake(m_pLead->getPositionX()-2.5f,m_pLead->getPositionY()-2.5f-MoveLength,5,5);
		if (update(leadRect))
		{
			this->m_pLead->setPositionY(this->m_pLead->getPositionY()-MoveLength);
		}
		else
		{
			
			MoveHeroEnd();
		}
		
		break;
	case kLeft:
		//获取移动后位置
		leadRect = CCRectMake(m_pLead->getPositionX()-2.5f-MoveLength,m_pLead->getPositionY()-2.5f,5,5);
		if (update(leadRect))
		{
			this->m_pLead->setPositionX(this->m_pLead->getPositionX()-MoveLength);
		}
		else
		{

			MoveHeroEnd();
		}
		
		break;
	case kRight:
		//获取移动后位置
		leadRect = CCRectMake(m_pLead->getPositionX()-2.5f+MoveLength,m_pLead->getPositionY()-2.5f,5,5);
		if (update(leadRect))
		{
			this->m_pLead->setPositionX(this->m_pLead->getPositionX()+MoveLength);
		}
		else
		{

			MoveHeroEnd();
		}
	
		break;
	default:
		break;
	}
}

/************************************************************************/
/* 精灵移动 停止                                                                     */
/************************************************************************/
void CCButtonLayer::MoveHeroEnd()
{
// 	CCWell * yellow_Sprite = CCWell::create("yellow.png",yellow_wall);
// 	this->addChild(yellow_Sprite);
// 
// 	CCFadeOut* fadeOut = CCFadeOut::create(0.2f);
// 	CCCallFuncN *callN = CCCallFuncN::create(this,callfuncN_selector(CCButtonLayer::callNodeBack));
// 	CCFiniteTimeAction * seq = CCSequence::create(fadeOut,callN,NULL);
// 	yellow_Sprite->runAction(seq);

	switch(m_pTagWell)
	{
	case kyellow:
		{
			CCWell * yellow_Sprite = CCWell::create("yellow.png",yellow_wall);
			this->addChild(yellow_Sprite);

			CCFadeOut* fadeOut = CCFadeOut::create(0.2f);
			CCCallFuncN *callN = CCCallFuncN::create(this,callfuncN_selector(CCButtonLayer::callNodeBack));
			CCFiniteTimeAction * seq = CCSequence::create(fadeOut,callN,NULL);
			yellow_Sprite->runAction(seq);
		}
		break;
	default:
		break;
	}


}


/************************************************************************/
/* 墙体消失                                                                     */
/************************************************************************/
void CCButtonLayer::callNodeBack(CCNode *sender)
{
	CCWell * sprite = (CCWell *)sender;
	this->removeChild(sprite);
}