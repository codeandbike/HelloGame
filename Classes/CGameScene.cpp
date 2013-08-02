#include "CGameScene.h"
#include <list>

using namespace cocos2d;
CCGameScene::CCGameScene(void)
{

}


CCGameScene::~CCGameScene(void)
{
}

bool CCGameScene::init() //初始化函数
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());
		//加载背景
		this->m_pBackground = CCSprite::create("Background.png");
		CC_BREAK_IF(!m_pBackground);
		this->m_pBackground->setPosition(ccp(0,0));
		this->m_pBackground->setAnchorPoint(ccp(0,0));
		this->addChild(m_pBackground);

		//加载游戏操作层

// 		this->m_pGameLayer = CCOperateScene::create();
// 		CC_BREAK_IF(!m_pGameLayer);
// 		this->addChild(m_pGameLayer);
 		int yellowArr[5][2] = {{1,0},{2,0},{3,0},{4,0},{5,0}};
// 		this->m_wall = CCLead::create("yellow.png",yellowArr,5);
// 		this->addChild(m_wall);
		

		//添加主角
		this->m_pLead = CCSprite::create("Lead.PNG");
		this->m_pLead->setPosition(ccp(200,200));
		this->addChild(m_pLead);

		//添加按钮
		this->m_pButton = CCButtonLayer::create();
		CC_BREAK_IF(!m_pButton);
		m_pButton->m_pLead = this->m_pLead;
		m_pButton->pGameLayer = m_pGameLayer;
		//this->m_pGameLayer->m_pSprite = m_pLead;
		this->addChild(m_pButton);

		list<CCPoint> temp;
		for (int i=0; i<5;i++)
		{
			CCPoint position = ccp((yellowArr[i][0]*10)+5,(yellowArr[i][1]*10)+150+5);
			temp.push_back(position);
		}
		m_pButton->yellow_wall = temp;
		

		//退出按钮
		CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
			"CloseNormal.png",
			"CloseSelected.png",
			this,
			menu_selector(CCGameScene::menuCloseCallback));
		CC_BREAK_IF(! pCloseItem);

		pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));
		CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
		pMenu->setPosition(CCPointZero);
		CC_BREAK_IF(! pMenu);

		this->addChild(pMenu, 1);

		bRet = true;
	} while (0);

	return bRet;
}
CCScene* CCGameScene::scene()//场景加载
{
	CCScene * scene = NULL;
	do 
	{
		scene = CCScene::create();
		CC_BREAK_IF(!scene);
		CCGameScene * gameScene = CCGameScene::create();
		CC_BREAK_IF(!gameScene);

		scene->addChild(gameScene);

	} while (0);

	return scene;
}

void CCGameScene::menuCloseCallback(CCObject* pSender)
{
	// "close" menu item clicked
	CCDirector::sharedDirector()->end();
}

