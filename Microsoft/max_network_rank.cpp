/*
Link: https://aonecode.com/microsoft-online-assessment-questions#mnr

Given a map of n cities, and m roads between them, returns the maximal network rank.

The network rank of a city is the total number of roads that are connected to the city. 

Write a function, given two arrays starts, ends consisting of m integers each and an integer n, where starts[i] and ends[i] are cities at the two ends of the i-th road.

Example:
Input:
starts = [1, 2, 3, 3]
ends = [2, 3, 1, 4]
n = 4
Output:
4
Explanation:
The chosen cities may be 2 and 3, and the four roads connected to them are: (2,1), (2,3), (3,1), (3,4).
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
public:
    void method(vi &a, vi &b, int n, int m){
        vi count(n + 1, 0);
        vvi isConnected(n+1, vi(n+1, 0));
        rep(i,0,m){
            int cityA = a[i], cityB = b[i];
            isConnected[cityA][cityB] = isConnected[cityB][cityA] = 1;
            count[cityA]++;
            count[cityB]++;
        }
        int maxRank = 0;
        rep(i,1,n+1){
            rep(j,i+1,n+1){
                maxRank = max(maxRank, count[i] + count[j] - isConnected[i][j]);
            }
        }
        cout<<maxRank<<endl;
    }
};

int32_t main(){
    int n, m;
    cin>>n>>m;
    vi a(m), b(m);
    inpvec(a, m);
    inpvec(b, m);
    Kaarti *ob = new Kaarti;
    ob->method(a, b, n, m);
    return 0;
}