#include "CGameScene.h"

using namespace cocos2d;
CCGameScene::CCGameScene(void)
{

}


CCGameScene::~CCGameScene(void)
{
}

bool CCGameScene::init() //³õÊ¼»¯º¯Êı
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());
		//¼ÓÔØ±³¾°
		this->m_pBackground = CCSprite::create("Background.png");
		CC_BREAK_IF(!m_pBackground);
		this->m_pBackground->setPosition(ccp(0,0));
		this->m_pBackground->setAnchorPoint(ccp(0,0));
		this->addChild(m_pBackground);

		//¼ÓÔØÓÎÏ·²Ù×÷²ã

		this->m_pGameLayer = CCOperateScene::create();
		CC_BREAK_IF(!m_pGameLayer);
		this->addChild(m_pGameLayer);

		//Ìí¼ÓÖ÷½Ç
		this->m_pLead = CCSprite::create("Lead.PNG");
		this->m_pLead->setPosition(ccp(200,200));
		this->addChild(m_pLead);

		//Ìí¼Ó°´Å¥
		this->m_pButton = CCButtonLayer::create();
		CC_BREAK_IF(!m_pButton);
		m_pButton->m_pLead = this->m_pLead;
		m_pButton->pGameLayer = m_pGameLayer;
		//this->m_pGameLayer->m_pSprite = m_pLead;
		this->addChild(m_pButton);

		//ÍË³ö°´Å¥
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
CCScene* CCGameScene::scene()//³¡¾°¼ÓÔØ
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

