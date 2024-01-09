#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <malloc.h>
#include "baza.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //пример работы со статической переменной
    Solder staticExample = *InputSolder();
    PrintSolder(staticExample);
    PrintVkaf(staticExample.vkaf);
    PrintVoenk(staticExample.voenk);
    ChangeStatus(&staticExample, 2);
    PrintSolder(staticExample);

    //пример работы с динамической
    Solder* dynamicExample = (Solder*)calloc(1, sizeof(Solder));
    char data[] = "15.12.2023";
    char time[] = "9.00";
    dynamicExample = CreateSolder(*InputVoenk(), *InputVkaf(), data, time, 2);
    PrintSolder(*dynamicExample);
    PrintVkaf(dynamicExample->vkaf);
    PrintVoenk(dynamicExample->voenk);
    ChangeStatus(dynamicExample, 2);
    PrintSolder(*dynamicExample);
    FreeSolderMemory(dynamicExample);
    free(dynamicExample);
}