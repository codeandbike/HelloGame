#include "CLead.h"

using namespace cocos2d;
CCLead::CCLead(void)
{

}


CCLead::~CCLead(void)
{

}

bool CCLead::init(const char *path,int Arr[][2],int n)
{
	bool sRet = false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());
		
	
		for (int i=0;i<n;i++)
		{	
				CCSprite * spLead = CCSprite::create(path);
				spLead->setPosition(ccp(Arr[i][0]*10+spLead->getContentSize().width/2,Arr[i][1]*10+150+spLead->getContentSize().height/2));
				this->addChild(spLead);
				spLead->setTag(1);
			
		}


		sRet = true;
	} while (0);
	return sRet;
}


CCLead *CCLead::create(const char *path,int Arr[][2],int n)
{
	CCLead *pRet = new CCLead();
	if (pRet && pRet->init(path,Arr,n))
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