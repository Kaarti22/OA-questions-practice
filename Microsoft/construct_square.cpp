/*
Link: https://aonecode.com/microsoft-online-assessment-questions#cs

There are two wooden sticks of lengths A and B respectively. Each of them can be cut into shorter sticks of integer lengths. Our goal is to construct the largest possible square. In order to do this, we want to cut the sticks in such a way as to achieve four sticks of the same length (note that there can be some leftover pieces). What is the longest side of square that we can achieve?
Write a function that given two integers A, B, returns the side length of the largest square that we can obtain. If it is not possible to create any square, the function should return 0.
Examples:
1. Given A = 10, B = 21, the function should return 7. We can split the second stick into
three sticks of length 7 and shorten the first stick by 3.
2. Given A = 13, B = 11, the function should return 5. We can cut two sticks of length 5
from each of the given sticks.
3. Given A = 2, B = 1, the function should return 0. It is not possible to make any square
from the given sticks.
4. Given A = 1, B = 8, the function should return 2. We can cut stick B into four parts.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define MOD 1000000007
#define pb push_back
#define popb pop_back
#define rep(i,a,b) for(int i=a; i<b; i++)
#define all(v) v.begin(),v.end()

void inparr(int arr[], int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void disarr(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void inpvec(vi &v, int n){
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
}

void disvec(vi v, int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

int madd(int a,int b) {
    return (a+b)%MOD;
}

int msub(int a,int b){
    return (((a-b)%MOD)+MOD)%MOD;
}

int mmul(int a,int b){
    return ((a%MOD)*(b%MOD))%MOD;
}

class Kaarti{
private:
    bool countPieces(int len, int a, int b){
        int sticks = a / len + b / len;
        return sticks >= 4;
    }

public:
    void method(int a, int b){
        int low = 1, high = (a + b)/4;
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(countPieces(mid, a, b)){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout<<ans<<endl;
    }
};

int32_t main(){
    int a, b;
    cin>>a>>b;
    Kaarti *ob = new Kaarti;
    ob->method(a, b);
    return 0;
}