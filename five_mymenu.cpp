#include "five_mymenu.h"

MENU_ITEM* ptr_origin,*ptr_root,*ptr_opera,*ptr_para_1,*ptr_para_2,*ptr_para_3;




void FIVEMENU_Init(void)
{
    //创建已知节点空间
    ptr_origin = (MENU_ITEM*)malloc(sizeof(MENU_ITEM));
    ptr_root = (MENU_ITEM*)malloc(4 * sizeof(MENU_ITEM));
    ptr_opera = (MENU_ITEM*)malloc(2 * sizeof(MENU_ITEM));
    ptr_para_1 = (MENU_ITEM*)malloc(PARA_CLASS_NUM * sizeof(MENU_ITEM));
    ptr_para_2 = (MENU_ITEM*)malloc(PARA_CLASS_NUM * sizeof(MENU_ITEM));
    ptr_para_3 = (MENU_ITEM*)malloc(PARA_CLASS_NUM * sizeof(MENU_ITEM));

    //注册已知节点
    //原点
    FIVEMENU_nodeCreate(ptr_origin, NULL, ptr_root, 4, menuType, "origin");

    //根目录
    FIVEMENU_nodeCreate(ptr_root, ptr_origin, ptr_opera, 2, menuType, "opera");
    FIVEMENU_nodeCreate(ptr_root + 1, ptr_origin, ptr_para_1, PARA_CLASS_NUM, menuType, "para1");
    FIVEMENU_nodeCreate(ptr_root + 2, ptr_origin, ptr_para_2, PARA_CLASS_NUM, menuType, "para2");
    FIVEMENU_nodeCreate(ptr_root + 3, ptr_origin, ptr_para_3, PARA_CLASS_NUM, menuType, "para3");

    //函数操作
    FIVEMENU_nodeCreate(ptr_opera, ptr_root, NULL, 0, saveType, "save_flash");
    //FIVEMENU_nodeCreate(ptr_opera+1, ptr_root, NULL, 0, variType, "para_switch");
                                                                                                    //单独写此处的数据注册

    //参数大类注册，个数到宏定义改



    //参数注册

}

//注册已知节点
void FIVEMENU_nodeCreate(MENU_ITEM*node_p,MENU_ITEM* node_father, MENU_ITEM* node_son, int32_t node_num,MENU_TYPE node_type, const char* item_Name)
{
    node_p->type = node_type;
    node_p->father = node_father;
    node_p->p_menu_type = node_son;
    node_p->itemNum = node_num;
    snprintf(node_p->menu_name, MENU_NAME_SIZE * sizeof(char), item_Name);
}


//创建参数大类节点信息
void FIVEMENU_menuCreate(int32_t node_offset, int32_t node_num, const char* item_Name)
{
    (ptr_para_1 + node_offset)->father = ptr_root + 1;
    (ptr_para_2 + node_offset)->father = ptr_root + 2;
    (ptr_para_3 + node_offset)->father = ptr_root + 3;
    (ptr_para_1 + node_offset)->itemNum = node_num;
    (ptr_para_2 + node_offset)->itemNum = node_num;
    (ptr_para_3 + node_offset)->itemNum = node_num;
    snprintf((ptr_para_1 + node_offset)->menu_name, MENU_NAME_SIZE * sizeof(char), item_Name);
    snprintf((ptr_para_2 + node_offset)->menu_name, MENU_NAME_SIZE * sizeof(char), item_Name);
    snprintf((ptr_para_3 + node_offset)->menu_name, MENU_NAME_SIZE * sizeof(char), item_Name);
    (ptr_para_1 + node_offset)->type = menuType;
    (ptr_para_2 + node_offset)->type = menuType;
    (ptr_para_3 + node_offset)->type = menuType;
    (ptr_para_1 + node_offset)->p_menu_type = (MENU_ITEM*)malloc(node_num * sizeof(MENU_ITEM));
    (ptr_para_2 + node_offset)->p_menu_type = (MENU_ITEM*)malloc(node_num * sizeof(MENU_ITEM));
    (ptr_para_3 + node_offset)->p_menu_type = (MENU_ITEM*)malloc(node_num * sizeof(MENU_ITEM));
}


//创建参数
void FIVEMENU_paraCreate(int32_t node_father_offset, MENU_TYPE node_type,void* ptr_data, int32_t node_offset, const char* item_Name,float node_max,float node_min)
{
    MENU_ITEM* para_1 = (ptr_para_1 + node_father_offset)->p_menu_type + node_offset;
    MENU_ITEM* para_2 = (ptr_para_2 + node_father_offset)->p_menu_type + node_offset;
    MENU_ITEM* para_3 = (ptr_para_3 + node_father_offset)->p_menu_type + node_offset;
    para_1->father = ptr_para_1 + node_father_offset;
    para_2->father = ptr_para_2 + node_father_offset;
    para_3->father = ptr_para_3 + node_father_offset;
    para_1->type = node_type;
    para_2->type = node_type;
    para_3->type = node_type;
    snprintf(para_1->menu_name, MENU_NAME_SIZE * sizeof(char), item_Name);
    snprintf(para_2->menu_name, MENU_NAME_SIZE * sizeof(char), item_Name);
    snprintf(para_3->menu_name, MENU_NAME_SIZE * sizeof(char), item_Name);
    if (node_type == variType)
    {
        para_1->p_int_type = (int_type_Handle_t*)malloc(sizeof(int_type_Handle_t));
        para_2->p_int_type = (int_type_Handle_t*)malloc(sizeof(int_type_Handle_t));
        para_3->p_int_type = (int_type_Handle_t*)malloc(sizeof(int_type_Handle_t));
        para_1->p_int_type->dataPtr = (int*)ptr_data;
        para_2->p_int_type->data = *(int*)ptr_data;
        para_3->p_int_type->data_max = node_max;
        para_1->p_int_type->data_min = node_min;
        para_2->p_int_type->dataPtr = (int*)ptr_data;
        para_3->p_int_type->data = *(int*)ptr_data;
        para_1->p_int_type->data_max = node_max;
        para_2->p_int_type->data_min = node_min;
        para_3->p_int_type->dataPtr = (int*)ptr_data;
        para_1->p_int_type->data = *(int*)ptr_data;
        para_2->p_int_type->data_max = node_max;
        para_3->p_int_type->data_min = node_min;
    }
    else
    {
        para_1->p_float_type = (float_type_Handle_t*)malloc(sizeof(float_type_Handle_t));
        para_2->p_float_type = (float_type_Handle_t*)malloc(sizeof(float_type_Handle_t));
        para_3->p_float_type = (float_type_Handle_t*)malloc(sizeof(float_type_Handle_t));
        para_1->p_float_type->dataPtr = (float*)ptr_data;
        para_2->p_float_type->data = *(float*)ptr_data;
        para_3->p_float_type->data_max = node_max;
        para_1->p_float_type->data_min = node_min;
        para_2->p_float_type->dataPtr = (float*)ptr_data;
        para_3->p_float_type->data = *(float*)ptr_data;
        para_1->p_float_type->data_max = node_max;
        para_2->p_float_type->data_min = node_min;
        para_3->p_float_type->dataPtr = (float*)ptr_data;
        para_1->p_float_type->data = *(float*)ptr_data;
        para_2->p_float_type->data_max = node_max;
        para_3->p_float_type->data_min = node_min;
    }
}