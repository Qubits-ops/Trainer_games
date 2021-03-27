#include <iostream>
#include "windows.h"

using namespace std;

DWORD t_Health = 0x0292A458;
DWORD R_Ammo = 0x292A4B0;
DWORD G_Ammo = 0x0292A49C;

HWND fenetre;
int main()
{
    fenetre = FindWindow(NULL,"AssaultCube");
    if(fenetre)
    {
        int userInput;
        cout << "Trainer Assault Cube" << endl;
        DWORD pid;
        GetWindowThreadProcessId(fenetre,&pid);
        HANDLE Process = OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
        for(int i = 0;i < 5;i++)
        {
            cout << ".";
            Sleep(100);
            cout << "" << endl;
        }
        cout << "Cheat Lancer" << endl;
        Beep(200,200);
        while(TRUE)
        {
            cout << "1 - INFINITE HEALTH" << endl;
            cout << "2 - INFINITE AMMO" << endl;
            cout << "3 - Quitter le trainer" << endl;
            cin >> userInput;
            if(userInput == 1)
            {
                int newNombresVies = 4000;
                WriteProcessMemory(Process,(LPVOID)t_Health,&newNombresVies,(DWORD)sizeof(newNombresVies),NULL);
            }
            else if(userInput == 2)
            {
                int newNombresAmmo = 1000;
                WriteProcessMemory(Process,(LPVOID)R_Ammo,&newNombresAmmo,(DWORD)sizeof(newNombresAmmo),NULL);
                WriteProcessMemory(Process,(LPVOID)G_Ammo,&newNombresAmmo,(DWORD)sizeof(newNombresAmmo),NULL);
            }
            else if(userInput == 3)
            {
                cout << "Merci d'avoir utiliser le trainer";
                break;
            }
            else
                cout << "Rentrez le bon numero" << endl;
        }



    }
    else
    {
        cout << "Programme non trouver";
    }
}
