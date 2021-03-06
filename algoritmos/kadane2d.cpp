#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define forc(i, n) for (int i = 0; i < int(n); i++) //for crescente
#define ford(i, n) for (int i = int(n-1); i >= 0; i--) //for decrescente
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> ii;
typedef long long LL;
typedef long double LD;
const int inf = 0x3f3f3f3f;
const int MX=1e6 + 20;


int kadaneAlgo(int arr[], int &start, int &end, int n) {    //find max sum and starting and ending location
   int sum = 0, maxSum = INT_MIN;
   end = -1;
   int tempStart = 0;
   for (int i = 0; i < n; i++) {
      sum += arr[i];
      if (sum < 0){
         sum = 0;
         tempStart = i+1;
      }
      else if (sum > maxSum) { 
         maxSum = sum;
         start = tempStart;
         end = i;
      }
   }
   if (end != -1) return maxSum;
   maxSum = arr[0];
   start = end = 0;
   for (int i = 1; i < n; i++) {
      if (arr[i] > maxSum) {
         maxSum = arr[i];
         start = end = i;
      }
   }
   return maxSum;
}

void maxSumRect(vector<vector<int>> mat,int n,int m) {
   int maxSum = INT_MIN, endLeft, endRight, endTop, endBottom;
   int left, right;
   int temp[n], sum, start, end;
   for (left = 0; left < m; left++) {
      for(int i = 0; i<n; i++) temp[i] = 0;
      for (right = left; right < m; ++right) {
         for (int i = 0; i < n; ++i) temp[i] += mat[i][right];
         sum = kadaneAlgo(temp, start, end, n);
         if (sum > maxSum) {
            maxSum = sum;
            endLeft = left;
            endRight = right;
            endTop = start;
            endBottom = end;
         }
      }
   }
   cout << maxSum << endl;
}

int main() {
    int n; cin >> n;
    vector<vector<int>> mat(n);
    forc(i,n){
        mat[i].resize(n);
        forc(j,n){
            cin >> mat[i][j];
        }
    }
    maxSumRect(mat,n,n);
}