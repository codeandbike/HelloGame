#include "COperateScene.h"
#include "CLead.h"


CCOperateScene::CCOperateScene(void)
{

	yellow_wall = new CCArray; //��ɫǽ��
	red_wall= new CCArray; //��ɫǽ��
	green_wall= new CCArray; //��ɫǽ��
	blue_wall= new CCArray; //��ɫǽ��
}


CCOperateScene::~CCOperateScene(void)
{
	if (yellow_wall != NULL)
	{
		yellow_wall->release();
		yellow_wall = NULL;
	}
	if (red_wall != NULL)
	{
		red_wall->release();
		red_wall = NULL;
	}
	if (green_wall != NULL)
	{
		green_wall->release();
		green_wall = NULL;
	}
	if (blue_wall != NULL)
	{
		blue_wall->release();
		blue_wall = NULL;
	}
}
/************************************************************************/
/*                      ��Ϸ������ʼ��                                   */
/************************************************************************/
bool CCOperateScene::init() //��Ϸ���ʼ��
{
	bool sRet = false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());

		//����ȡֵ��Χ[0][0] -> [27][32]
		
		//���ػ�ɫǽ��
		int yelloArr[5][2] = {{1,0},{2,0},{3,0},{4,0},{5,0}};
		yellow_wall = CreateWall("yellow.png",yelloArr,5);
// 		this->InitWall(yellow_wall);
// 
// 		int redArr[5][2] = {{1,4},{2,4},{3,4},{4,4},{5,4}};
// 		red_wall = CreateWall("red.png",redArr,5);
// 		this->InitWall(red_wall);
// 
// 		int greenArr[5][2] = {{1,8},{2,8},{3,8},{4,8},{5,8}};
// 		green_wall = CreateWall("green.png",greenArr,5);
// 		this->InitWall(green_wall);
// 
// 		int blueArr[5][2] = {{1,12},{2,12},{3,12},{4,12},{5,12}};
// 		blue_wall = CreateWall("blue.png",blueArr,5);
// 		this->InitWall(blue_wall);


        

		//���غ�ɫǽ��
// 		int redArr[5][2] = {{1,4},{2,4},{3,4},{4,4},{5,4}};
// 		CCLead * redLayer = CCLead::create("red.PNG",redArr,5);
// 		this->addChild(redLayer);


		//������ɫǽ��

// 		int greenArr[5][2] = {{1,6},{2,6},{3,6},{4,6},{5,6}};
// 		CCLead * greenLayer = CCLead::create("green.PNG",greenArr,27);
// 
// 		this->addChild(greenLayer);

		//������ɫǽ��
// 		int blueArr[5][2] = {{1,8},{2,8},{3,8},{4,8},{27,32}};
// 		CCLead * blueLayer = CCLead::create("blue.PNG",blueArr,5);
// 		this->addChild(blueLayer);

		//��ײ����
		//this->schedule(schedule_selector(CCOperateScene::update,1));

		sRet = true;
	} while (0);
	return sRet;
}

/************************************************************************/
/*                       ��������                                        */
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

// void CCOperateScene::update(float dt) //�����ײ
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
// 	this->InitWall(blue_wall);
// 
// 	}



/************************************************************************/
/*                       ����ǽ��                                        */
/************************************************************************/
CCArray * CCOperateScene::CreateWall(const char * ch,int Arr[][2],int n)
{
	//int Arr[5][2] = {{1,0},{2,0},{3,0},{4,0},{6,0}};
	CCArray * _wall = CCArray::create();
	for (int i = 0; i<n;i++)
	{
		CCSprite * projectile = CCSprite::create(ch);
		CCPoint Tilecoor = ccp(Arr[i][0],Arr[i][1]);
		projectile->setPosition(TilecoorToPosition(Tilecoor));
		this->addChild(projectile);
		_wall->addObject(projectile);

	}

	return _wall;
}

/************************************************************************/
/*            //����ת������λ������ת����cocos2dx����                     */
/************************************************************************/
CCPoint CCOperateScene::TilecoorToPosition(CCPoint tilecoor)
{
	CCPoint position = ccp((tilecoor.x*10)+5,(tilecoor.y*10)+150+5);
	return position;
}

/************************************************************************/
/*                       ��ʼ������ʾǽ��                                */
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