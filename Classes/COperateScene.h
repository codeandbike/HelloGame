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
	CCArray * yellow_wall; //黄色墙体
	CCArray * red_wall; //黄色墙体
	CCArray * green_wall; //黄色墙体
	CCArray * blue_wall; //黄色墙体


public:
	/************************************************************************/
	/*                      游戏场景初始化                                   */
	/************************************************************************/
	virtual bool init(); 
	/************************************************************************/
	/*                       创建场景                                        */
	/************************************************************************/
	static CCOperateScene * create(); 
	/************************************************************************/
	/*                       创建墙体                                        */
	/************************************************************************/
	CCArray * CreateWall(const char * ch,int Arr[][2],int n); 
	/************************************************************************/
	/*            //坐标转换，将位置坐标转换成cocos2dx坐标                     */
	/************************************************************************/
	CCPoint TilecoorToPosition(CCPoint tilecoor); 
	/************************************************************************/
	/*                       初始化并显示墙体                                */
	/************************************************************************/
	void InitWall(CCArray * _wall); 


	//void update(float dt); //检测碰撞
};

#endif
