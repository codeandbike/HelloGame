#include "CButtonLayer.h"


CCButtonLayer::CCButtonLayer(void)
{
	b_ButtonDown = false;
	m_pMove = NULL;
	m_pWell = NULL;
	arrWell = new CCArray;

	MoveLength = CCDirector::sharedDirector()->getWinSize().width*(8/480);
	//初始化障碍物结构体
	//数组取值范围[0][0] -> [27][32]
	int yellowArr[118][2] = {{0,0},{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,8},{0,9},{0,10},{0,11},{0,12},{0,13},{0,14},{0,15},{0,16},{0,17},{0,18},{0,19},{0,20},{0,21},{0,22},{0,23},{0,24},{0,25},{0,26},{0,27},{0,28},{0,29},{0,30},{0,31},{0,32},{27,0},{27,1},{27,2},{27,3},{27,4},{27,5},{27,6},{27,7},{27,8},{27,9},{27,10},{27,11},{27,12},{27,13},{27,14},{27,15},{27,16},{27,17},{27,18},{27,19},{27,20},{27,21},{27,22},{27,23},{27,24},{27,25},{27,26},{27,27},{27,28},{27,29},{27,30},{27,31},{27,32},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},{10,0},{11,0},{12,0},{13,0},{14,0},{15,0},{16,0},{17,0},{18,0},{19,0},{20,0},{21,0},{22,0},{23,0},{24,0},{25,0},{26,0},{1,32},{2,32},{3,32},{4,32},{5,32},{6,32},{7,32},{8,32},{9,32},{10,32},{11,32},{12,32},{13,32},{14,32},{15,32},{16,32},{17,32},{18,32},{19,32},{20,32},{21,32},{22,32},{23,32},{24,32},{25,32},{26,32}};
	int redArr[5][2] = {{1,4},{2,4},{3,4},{4,4},{5,4}};
	int greenArr[5][2] = {{1,8},{2,8},{3,8},{4,8},{5,8}};
	int blueArr[5][2] = {{1,12},{2,12},{3,12},{4,12},{5,12}};
	
	scene1_wall.yellow_wall = initList(yellowArr,118);
	scene1_wall.red_wall = initList(redArr,5);
	scene1_wall.green_wall = initList(greenArr,5);
	scene1_wall.blue_wall = initList(blueArr,5);
	

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
	if (!b_ButtonDown)
	{	
		dirTag = kUp;
		this->schedule(schedule_selector(CCButtonLayer::MoveHeroBegin),0.005f);
		b_ButtonDown = true;
	}
	



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
	if (!b_ButtonDown)
	{
		dirTag = kDown;
		this->schedule(schedule_selector(CCButtonLayer::MoveHeroBegin),0.005f);
		b_ButtonDown = true;
	}

	
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
	if (!b_ButtonDown)
	{
		b_ButtonDown = true;
		dirTag = kLeft;
		this->schedule(schedule_selector(CCButtonLayer::MoveHeroBegin),0.005f);
	}



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
	if (!b_ButtonDown)
	{
		dirTag = kRight;
		this->schedule(schedule_selector(CCButtonLayer::MoveHeroBegin),0.005f);
		b_ButtonDown=true;
	}

	
}


void CCButtonLayer::touchDragInsideUp2(CCObject* pSender, CCControlEvent event)
{
// 	this->m_pLead->stopAction(this->m_pMove);
// 	this->unschedule(schedule_selector(CCButtonLayer::update));
	if (dirTag == kUp)
	{
		this->unschedule(schedule_selector(CCButtonLayer::MoveHeroBegin));
		b_ButtonDown = false;
	}


}
void CCButtonLayer::touchDragInsideDown2(CCObject* pSender, CCControlEvent event)
{

// 	this->m_pLead->stopAction(this->m_pMove);
// 	this->unschedule(schedule_selector(CCButtonLayer::update));
	if (dirTag == kDown)
	{
		this->unschedule(schedule_selector(CCButtonLayer::MoveHeroBegin));
		b_ButtonDown = false;
	}

}
void CCButtonLayer::touchDragInsideLeft2(CCObject* pSender, CCControlEvent event)
{
// 	this->m_pLead->stopAction(this->m_pMove);
// 	this->unschedule(schedule_selector(CCButtonLayer::update));
	if (dirTag == kLeft)
	{
		this->unschedule(schedule_selector(CCButtonLayer::MoveHeroBegin));
		b_ButtonDown = false;
	}

}
void CCButtonLayer::touchDragInsideRight2(CCObject* pSender, CCControlEvent event)
{
// 	this->m_pLead->stopAction(this->m_pMove);
// 	this->unschedule(schedule_selector(CCButtonLayer::update));
	if (dirTag == kRight)
	{
		this->unschedule(schedule_selector(CCButtonLayer::MoveHeroBegin));
		b_ButtonDown = false;
	}

}


bool CCButtonLayer::update(CCRect leadRect ) //检测碰撞
{
	struct_wall scene_wall = scene1_wall;
	list<CCPoint>::iterator iter;
	//判断是否撞上黄色墙体
	for (iter = scene_wall.yellow_wall.begin();iter!=scene_wall.yellow_wall.end();iter++)
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
	//判断是否撞上红色墙体
	for (iter = scene_wall.red_wall.begin();iter!=scene_wall.red_wall.end();iter++)
	{
		//list<CCPoint>::iterator iter = yellow_wall.begin()+i;
		CCPoint temp = *iter;
		CCRect wellRect = CCRectMake(temp.x-5,temp.y-5,10,10); 
		if (leadRect.intersectsRect(wellRect))
		{
			m_pTagWell = kred;
			return false;
		}

	}

	//判断是否撞上绿色墙体
	for (iter = scene_wall.green_wall.begin();iter!=scene_wall.green_wall.end();iter++)
	{
		//list<CCPoint>::iterator iter = yellow_wall.begin()+i;
		CCPoint temp = *iter;
		CCRect wellRect = CCRectMake(temp.x-5,temp.y-5,10,10); 
		if (leadRect.intersectsRect(wellRect))
		{
			m_pTagWell = kgreen;
			return false;
		}

	}

	//判断是否撞上蓝色墙体
	for (iter = scene_wall.blue_wall.begin();iter!=scene_wall.blue_wall.end();iter++)
	{
		//list<CCPoint>::iterator iter = yellow_wall.begin()+i;
		CCPoint temp = *iter;
		CCRect wellRect = CCRectMake(temp.x-5,temp.y-5,10,10); 
		if (leadRect.intersectsRect(wellRect))
		{
			m_pTagWell = kblue;
			return false;
		}

	}

	//判断是否出界

// 	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
// 	if (leadRect.getMaxX()>winSize.width && leadRect.getMaxY() > winSize.height && leadRect.getMinX()<0 && leadRect.getMinY()<0)
// 	{
// 		return false;
// 	}


	return true;

}

/************************************************************************/
/* 精灵移动 开始                                                          */
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

	struct_wall scene_wall = scene1_wall;

	switch(m_pTagWell)
	{
	case kyellow:
		{
			CCWell * yellow_Sprite = CCWell::create("yellow.png",scene_wall.yellow_wall);
			this->addChild(yellow_Sprite);

			CCFadeOut* fadeOut = CCFadeOut::create(0.2f);
			CCCallFuncN *callN = CCCallFuncN::create(this,callfuncN_selector(CCButtonLayer::callNodeBack));
			CCFiniteTimeAction * seq = CCSequence::create(fadeOut,callN,NULL);
			yellow_Sprite->runAction(seq);
		}
		break;

	case kred:
		{
			CCWell * red_Sprite = CCWell::create("red.png",scene_wall.red_wall);
			this->addChild(red_Sprite);

			CCFadeOut* fadeOut = CCFadeOut::create(0.2f);
			CCCallFuncN *callN = CCCallFuncN::create(this,callfuncN_selector(CCButtonLayer::callNodeBack));
			CCFiniteTimeAction * seq = CCSequence::create(fadeOut,callN,NULL);
			red_Sprite->runAction(seq);
		}
		break;
	case kgreen:
		{
			CCWell * green_Sprite = CCWell::create("green.png",scene_wall.green_wall);
			this->addChild(green_Sprite);

			CCFadeOut* fadeOut = CCFadeOut::create(0.2f);
			CCCallFuncN *callN = CCCallFuncN::create(this,callfuncN_selector(CCButtonLayer::callNodeBack));
			CCFiniteTimeAction * seq = CCSequence::create(fadeOut,callN,NULL);
			green_Sprite->runAction(seq);
		}
		break;
	case kblue:
		{
			CCWell * blue_Sprite = CCWell::create("blue.png",scene_wall.blue_wall);
			this->addChild(blue_Sprite);

			CCFadeOut* fadeOut = CCFadeOut::create(0.2f);
			CCCallFuncN *callN = CCCallFuncN::create(this,callfuncN_selector(CCButtonLayer::callNodeBack));
			CCFiniteTimeAction * seq = CCSequence::create(fadeOut,callN,NULL);
			blue_Sprite->runAction(seq);
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



list<CCPoint> CCButtonLayer::initList(int arr[][2],int n)
{
	list<CCPoint> temp;
	for (int i=0; i<n;i++)
	{
		int k = arr[i][0];
		int j = arr[i][1];
		temp.push_back(ccp((k*10)+5,(j*10)+150+5));
	}
	return temp;

}