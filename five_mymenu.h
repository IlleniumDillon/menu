#pragma once

//vs��
#include "stdint.h"
#include <stdlib.h>
#include "string.h"
//

#include "hitsic_common.h"

//�궨��
#define MENU_NAME_SIZE 20
#define PARA_CLASS_NUM 2




typedef enum menu_type_t
{
    menuType,              //�Ӳ˵�����
    variType,             //����int��
    varfType,              //����float��
    saveType               //���浽flash�ĺ���
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

//�˵��ṹ��
typedef struct menu_item
{
    enum menu_type_t type;
    struct menu_item* father;
    union
    {
        int_type_Handle_t* p_int_type;
        float_type_Handle_t* p_float_type;      //���ӹ�����
        MENU_ITEM* p_menu_type;
    };
    char menu_name[MENU_NAME_SIZE];
    union
    {
        int32_t itemNum;                        //�Ӳ˵��������д���
        int32_t sector;
    };
}MENU_ITEM;

//״̬���ṹ��
typedef struct Current_State
{
    //���λ��
    uint32_t cursorPosition_x;      
    uint32_t cursorPosition_y;
    //�ڼ���
    uint32_t order_Now;
    //��ǰ�Ӳ˵�����
    uint32_t itemNum_Now;
    //�˵����ַ
    MENU_ITEM* ptr_Now;
}CURRENT_STATE;


//��������

//������ע��
void FIVEMENU_nodeCreate(MENU_ITEM* node_p, MENU_ITEM* node_father, MENU_ITEM* node_son, int32_t node_num, MENU_TYPE node_type, const char* item_Name);








