#ifndef __WELL_SCENE_H__
#define __WELL_SCENE_H__

#include "cocos2d.h"

#include "cocos-ext.h" 

#include <list>

using namespace std;
using namespace cocos2d;
class CCWell : public cocos2d::CCLayer
{
public:
	CCWell(void);
	~CCWell(void);

private:
	
public:
	virtual bool init(const char * ch,list<CCPoint> points); // ͼ���ʼ��
	
	static CCWell * create(const char * ch,list<CCPoint> points);//����ͼ��
};

#endif