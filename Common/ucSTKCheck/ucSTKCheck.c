/************************************************************************
* Copyright (C) 2020 Nercita
*
* �ļ����ƣ� ucSTKCheck.c
* �ļ���ʶ��
* ����ժҪ�� ucSTKCheck��غ�������
* ����˵����
* ��ǰ�汾��
* ��    �ߣ� woody
* ������ڣ� 2020.09.07
*
* �޸ļ�¼1��
*    �޸����ڣ�
*    �� �� �ţ�
*    �� �� �ˣ�
*    �޸����ݣ�
* �޸ļ�¼2����
************************************************************************/
#include "ucSTKCheck.h"
#include "MainConfig.h"

#define TASK_ALLCOUNT   4  //����������

//�����¼
//��Ҫд��Ҫ��ص��������
const TASK_STACK_INFO cg_TaskBuff[TASK_ALLCOUNT] = {
    {(uint32_t)START_TASK_STK, START_STK_SIZE, START_TASK_PRIO},
	{(uint32_t)PWR_TASK_STK, PWR_STK_SIZE, PWR_TASK_PRIO},
    {(uint32_t)Runing_TASK_STK, Runing_State_STK_SIZE, Runing_State_PRIO},
	{(uint32_t)Parm_TASK_STK, Parm_STK_SIZE, Parm_State_PRIO},
};

/**************************************************************************
* ��������: FindFirstNonzeroPosition
* ��������: �Ӷ�ջ�ײ������ҵ���һ����0λ�ã�����ƫ�ƣ���
* �������: pStackBottom��ջ�׵�ַ��StackSize�������ջ��С
* �������: ��
* �� �� ֵ: ��
* -----------------------------------------------
* 2020/09/07       V1.0      woody         ����
**************************************************************************/
uint32_t FindFirstNonzeroPosition(uint32_t *pStackBottom, uint32_t StackSize)
{
    uint32_t i = 0;

    for (i = 0; i < StackSize; i ++) {
        if (pStackBottom[i] != 0) break;
    }

    return i;
}

/**************************************************************************
* ��������: TaskStackMonitor
* ��������: ����״̬��أ���ӡ�����ջ״̬
* �������: ��
* �������: ��
* �� �� ֵ: ��
* -----------------------------------------------
* 2020/09/07       V1.0      woody         ����
**************************************************************************/
void TaskStackMonitor(void)
{
    uint32_t i;
    uint32_t StackBottomAddr;   //ջ�׵�ַ
    uint32_t StackResidual;     //��ջʣ��
	
#if DEBUG_LOG_PRINTF
    OS_CPU_SR cpu_sr = 0;
    LOG_I("----------------Task status----------------");
#endif
    for (i = 0; i < sizeof(cg_TaskBuff) / sizeof(TASK_STACK_INFO); i ++) {
        StackBottomAddr = cg_TaskBuff[i].StackTopAddr + 4;                                                  //����ջ�׵�ַ
        StackResidual = FindFirstNonzeroPosition((uint32_t *)StackBottomAddr, cg_TaskBuff[i].StackSize);    //����ʹ����
#if DEBUG_LOG_PRINTF
        LOG_I("|Task ID: %d, Remaining Stack SIZE: %dBYTE, Usage Amount: %d%%", 
				cg_TaskBuff[i].Proi, StackResidual,
				(cg_TaskBuff[i].StackSize - StackResidual) * 100 / cg_TaskBuff[i].StackSize);
#endif
    }
#if DEBUG_LOG_PRINTF
    LOG_I("CPU Usage: %d%%", OSCPUUsage);
    LOG_I("----------------------------------------");
#endif
}


