//Print Mirror Image of a 2-D array
//http://www.mycodeschool.com/problems/print-mirror-image-of-a-2-d-array

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    int testcase;
    char c;
    //First line of input will contain a number T = number of test cases
    cin >> testcase;
    
    
    while (testcase>0) {
        int entry;
        int length;
        char arr[50][50];
        
        //Each test case will contain two positive integers n and m 
        //(1<=n, m<=50) on a single line separated by space.
        //Next n lines will each contain a string of exactly m characters.
        cin >> entry >> length;
        
        for(int i=0; i<entry; i++)
        {
            for(int j=0; j<length; j++)
            { 
                cin >> arr[i][j];
            }
        }
    
        //Next line will contain a character 'V' or 'H'
        cin >> c;
        //Mirror is placed vertically along the right-most column.
        if (c == 'V')
        {
            for(int i=0; i<entry; i++)
            {
                for(int j=length-1; j>=0; j--)
                { 
                    cout<< arr[i][j];
                }
                cout <<endl;
            }
  
        }
        //Mirror is placed horizontally along the bottom-most row.
        else if (c == 'H') 
        {
            for (int i=entry-1; i>=0 ; i--)
            {
                for(int j=0; j<length; j++)
                {
                    cout << arr[i][j];
                }
                cout << endl;
            }
            
        }
        testcase--;
        cout << endl;
        
    }
    
    return 0;
}

