#include "COperateScene.h"
#include "CLead.h"


CCOperateScene::CCOperateScene(void)
{
}


CCOperateScene::~CCOperateScene(void)
{
}
/************************************************************************/
/*                      游戏场景初始化                                   */
/************************************************************************/
bool CCOperateScene::init() //游戏层初始化
{
	bool sRet = false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());

		//数组取值范围[0][0] -> [27][32]
		
		//加载黄色墙体
		int yelloArr[5][2] = {{1,0},{2,0},{3,0},{4,0},{5,0}};
		yellow_wall = CreateWall();
		this->InitWall(yellow_wall);
        
		

		//加载红色墙体
// 		int redArr[5][2] = {{1,4},{2,4},{3,4},{4,4},{5,4}};
// 		CCLead * redLayer = CCLead::create("red.PNG",redArr,5);
// 		this->addChild(redLayer);


		//加载绿色墙体

// 		int greenArr[5][2] = {{1,6},{2,6},{3,6},{4,6},{5,6}};
// 		CCLead * greenLayer = CCLead::create("green.PNG",greenArr,27);
// 
// 		this->addChild(greenLayer);

		//加载蓝色墙体
// 		int blueArr[5][2] = {{1,8},{2,8},{3,8},{4,8},{27,32}};
// 		CCLead * blueLayer = CCLead::create("blue.PNG",blueArr,5);
// 		this->addChild(blueLayer);

		//碰撞触发
		//this->schedule(schedule_selector(CCOperateScene::update));

		sRet = true;
	} while (0);
	return sRet;
}

/************************************************************************/
/*                       创建场景                                        */
/************************************************************************/
CCOperateScene *CCOperateScene::create() 
{
	CCOperateScene *pRet = new CCOperateScene();
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

// void CCOperateScene::update(float dt) //检测碰撞
// {
// 	CCObject* it;
// 	CCARRAY_FOREACH(this->greenArray,it)
// 	{
// 		CCSprite * pWellSprite = dynamic_cast<CCSprite*>(it);
// 		CCRect wellRect = CCRectMake(pWellSprite->getPositionX()-pWellSprite->getContentSize().width/2,
// 			pWellSprite->getPositionY()-pWellSprite->getContentSize().height/2,
// 			pWellSprite->getContentSize().width,pWellSprite->getContentSize().height);
// 
// 		CCRect LeadRect = CCRectMake(m_pSprite->getPositionX()-2.5f,m_pSprite->getPositionY()-2.5f,2.5f,2.5f);
// 
// 		if (LeadRect.intersectsRect(wellRect))
// 		{
// 			m_pSprite->stopAction(pBut->m_pMove);
// 		}
// 
// 	}
// 
//

/************************************************************************/
/*                       创建墙体                                        */
/************************************************************************/
CCArray * CCOperateScene::CreateWall()
{
	int Arr[5][2] = {{1,0},{2,0},{3,0},{4,0},{6,0}};
	CCArray * _wall = CCArray::create();
	for (int i = 0; i<5;i++)
	{
		CCSprite * projectile = CCSprite::create("yellow.PNG");
		CCPoint Tilecoor = ccp(Arr[i][0],Arr[i][1]);
		projectile->setPosition(TilecoorToPosition(Tilecoor));
		//this->addChild(projectile);
		_wall->addObject(projectile);

	}

	return _wall;
}

/************************************************************************/
/*            //坐标转换，将位置坐标转换成cocos2dx坐标                     */
/************************************************************************/
CCPoint CCOperateScene::TilecoorToPosition(CCPoint tilecoor)
{
	CCPoint position = ccp((tilecoor.x*10)+5,(tilecoor.y*10)+150+5);
	return position;
}

/************************************************************************/
/*                       初始化并显示墙体                                */
/************************************************************************/
void CCOperateScene::InitWall(CCArray * _wall)
{
	CCObject * iw;
	CCARRAY_FOREACH(_wall,iw)
	{
		CCSprite * pWellSprite = dynamic_cast<CCSprite *>(iw);
		this->addChild(pWellSprite);
	}
}