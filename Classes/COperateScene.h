#ifndef __OPERATE_SCENE_H__
#define __OPERATE_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace std;

class CCOperateScene : public cocos2d::CCLayer
{
public:
	CCOperateScene(void);
	~CCOperateScene(void);
public:
	//cocos2d::CCMoveBy *m_pMove;
	//cocos2d::CCSprite * m_pSprite;
	CCArray * yellow_wall; //��ɫǽ��
	CCArray * red_wall; //��ɫǽ��
	CCArray * green_wall; //��ɫǽ��
	CCArray * blue_wall; //��ɫǽ��


public:
	/************************************************************************/
	/*                      ��Ϸ������ʼ��                                   */
	/************************************************************************/
	virtual bool init(); 
	/************************************************************************/
	/*                       ��������                                        */
	/************************************************************************/
	static CCOperateScene * create(); 
	/************************************************************************/
	/*                       ����ǽ��                                        */
	/************************************************************************/
	CCArray * CreateWall(const char * ch,int Arr[][2],int n); 
	/************************************************************************/
	/*            //����ת������λ������ת����cocos2dx����                     */
	/************************************************************************/
	CCPoint TilecoorToPosition(CCPoint tilecoor); 
	/************************************************************************/
	/*                       ��ʼ������ʾǽ��                                */
	/************************************************************************/
	void InitWall(CCArray * _wall); 


	//void update(float dt); //�����ײ
};

#endif
