#include "CWell.h"
using namespace cocos2d;

CCWell::CCWell(void)
{
}


CCWell::~CCWell(void)
{
}


bool CCWell::init(const char * ch,list<CCPoint> points) // 图层初始化
{
	bool sRet = false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());

		list<CCPoint>::iterator iter;
		for (iter = points.begin();iter != points.end(); iter++)
		{
			CCPoint poitn = *iter;
			CCSprite * spLead = CCSprite::create(ch);
			spLead->setPosition(poitn);
			this->addChild(spLead);
		}

		sRet = true;
	} while (0);

	return sRet;
}

CCWell * CCWell::create(const char * ch,list<CCPoint> points)//创建图层
{
	CCWell *pRet = new CCWell();
	if (pRet && pRet->init(ch,points))
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