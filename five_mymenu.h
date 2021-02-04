#pragma once

//vs用
#include "stdint.h"
#include <stdlib.h>
#include "string.h"
//

#include "hitsic_common.h"

//宏定义
#define MENU_NAME_SIZE 20
#define PARA_CLASS_NUM 2




typedef enum menu_type_t
{
    menuType,              //子菜单类型
    variType,             //操作int型
    varfType,              //操作float型
    saveType               //保存到flash的函数
}MENU_TYPE;


typedef struct int_type_Handle
{
    float data_max;
    float data_min;
    int32_t* dataPtr;
    int32_t data;
}int_type_Handle_t;

typedef struct float_type_Handle
{
    float data_max;
    float data_min;
    float* dataPtr;
    float data;
}float_type_Handle_t;

//菜单结构体
typedef struct menu_item
{
    enum menu_type_t type;
    struct menu_item* father;
    union
    {
        int_type_Handle_t* p_int_type;
        float_type_Handle_t* p_float_type;      //链接共用体
        MENU_ITEM* p_menu_type;
    };
    char menu_name[MENU_NAME_SIZE];
    union
    {
        int32_t itemNum;                        //子菜单个数或读写编号
        int32_t sector;
    };
}MENU_ITEM;

//状态机结构体
typedef struct Current_State
{
    //光标位置
    uint32_t cursorPosition_x;      
    uint32_t cursorPosition_y;
    //第几个
    uint32_t order_Now;
    //当前子菜单总数
    uint32_t itemNum_Now;
    //菜单项地址
    MENU_ITEM* ptr_Now;
}CURRENT_STATE;


//函数声明

//创建与注册
void FIVEMENU_nodeCreate(MENU_ITEM* node_p, MENU_ITEM* node_father, MENU_ITEM* node_son, int32_t node_num, MENU_TYPE node_type, const char* item_Name);








