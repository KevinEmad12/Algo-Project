// Project.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include<algorithm>
#include <iostream>
using namespace std;
//Dynamic Programming -- Bottom-up approach
//Complexity : O(N^2) 
int minJumps(int arr[], int n)
{
    int count = 1;
    int* jumps = new int[n];                 //Array to store solutions of the n different sub-problems

    jumps[0] = 0;                            //Since we are standing at the first index and we need no jumps to reach the first element

    for (int i = 1; i < n; i++) {
        jumps[i] = INT_MAX;                  //We initialize every new sub-problem with INF
        for (int j = 0; j < i; j++) {
            if (i <= j + arr[j] && jumps[j] != INT_MAX) {
                jumps[i] = min(jumps[i], jumps[j] + 1);    //Calculate the solution of the smaller sub-problem in an iterative way.
                break;
            }
        }
    }
    
    return jumps[n - 1];
}

int main()
{
    int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
    int size=sizeof(arr)/sizeof(int); //size of array (6*4)/4 = 6
 
    cout << "Minimum number of jumps to reach end is " << minJumps(arr, size);
    return 0;
}
