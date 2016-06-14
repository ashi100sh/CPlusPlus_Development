//http://www.mycodeschool.com/problems/number-of-zeroes-in-n
//Problem: Given a number n, find out the number of zeroes at the end of decimal
//representation of n!
#include<iostream>
#include<cstdio>
#include<cmath>
// Include headers as needed

using namespace std;

//This method return number of zero in n!
int findZeroForNumber(int number)
{
    int noOfZero = 0;
    for (int i=5; i<=number; i=i*5)
    {
        int count = number/i;
        noOfZero += count;
    }
    
    return noOfZero;
}

int main()
{
    int testcase;
    int number = 0;
    cin >> testcase;
    while(testcase != 0)
    {
        cin >> number;
        cout << findZeroForNumber(number) << endl;
        testcase --;
    }
    return 0;
}

