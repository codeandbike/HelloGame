#ifndef __LEAD_SCENE_H__
#define __LEAD_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
class CCLead : public cocos2d::CCLayer
{
public:
	CCLead(void);
	~CCLead(void);



public:
	virtual bool init(const char *path,CCArray * arrPosition);//³õÊ¼»¯Ö÷½Ç
	static CCLead * create(const char *path,CCArray * arrPosition); 

};

#endif