//
//  main.cpp
//  Sudoku
//
//  Created by Miguel Bazán on 8/14/15.
//  Copyright (c) 2015 MiguelBazan. All rights reserved.
//

#include <iostream>
using namespace std;
void leer (int *iMat)
{
    for (int iR = 0; iR < 9; iR++)
    {
        for (int iC = 0 ; iC < 9; iC++)
        {
            cin >> iMat[iR * 9 + iC];
        }
    }
}
int main(int argc, const char * argv[])
{
    bool bValor[9];
    int *iMat = new int [81];
    
    leer(iMat);

    for (int iR = 0; iR < 9; iR+=3)
    {
        for (int iC = 0; iC < 9; iC += 3)
        {
            for (int iA = 0; iA < 9; iA++)
            {
                bValor[iA] = false;
            }
            for (int iB = 0; iB < 3; iB++)
            {
                for (int iD = 0; iD < 3; iD++)
                {
                    int iAux = iMat[(iB + iR) * 9 + iD + iC];
                    if (bValor[iAux -1] == true)
                    {
                        cout<<"NO"<<endl;
                        return 0;
                    }
                    else
                    {
                        bValor[iAux -1] = true;
                    }
                }
            }
        }
    }
    
    for (int iR = 0; iR < 9; iR++)
    {
        for (int iC = 0;iC < 9; iC++)
        {
            bValor[iC] = false;
        }
        
        for (int iA = 0; iA < 9; iA++)
        {
            int iAux = iMat[(iR) * 9 + iA];
            
            if (bValor[iAux- 1 ] == true)
            {
                cout<<"NO"<<endl;
                return 0;
            }
            else
            {
                bValor[iAux - 1] = true;
            }
        }
    }
    
    
    for (int iR = 0; iR < 9; iR++)
    {
        for (int iK = 0; iK < 9; iK++)
        {
            bValor[iK] = false;
        }
        
        for (int iC = 0; iC < 9; iC++)
        {
            int iAux = iMat[(iC) * 9 + iR];
            if (bValor[iAux - 1] == true)
            {
                cout<<"NO"<<endl;
                return 0;
            }
            else
            {
                bValor[iAux - 1] = true;
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}