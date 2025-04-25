#pragma once
#include <windows.h>

//활성화, 비활성화 주석으로 가능
#define PROFILE

#ifdef PROFILE
#define PRO_BEGIN(TagName)	ProfileBegin(TagName)
#define PRO_END(TagName)	ProfileEnd(TagName)
#define PRO_OUT(FileName)	ProfileDataOutText(FileName)
#define PRO_RESET()			ProfileReset()
#define PRO_PRINT_OUT()		ProfilePrintOut()
//#define PRO_DEBUG()			PrintDataForDebug()
#else
#define PRO_BEGIN(TagName)
#define PRO_END(TagName)
#define PRO_OUT(TagName)	
#define PRO_RESET()			
#define PRO_PRINT_OUT()
#endif

struct _PROFILE_RESULT;
void ProfileBegin(const WCHAR* szName);
void ProfileEnd(const WCHAR* szName);
void ProfileDataOutText(const WCHAR* szFileName);
void ProfileReset(void);
void ProfilePrintOut(void);
//void PrintDataForDebug(void);
