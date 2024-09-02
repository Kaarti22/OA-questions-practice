/*
Link: https://leetcode.com/discuss/interview-question/5100121/Microsoft-Online-Assesement-Questions-2024/

u r given an undirected graph consisting of N vertices, numbered from 1 to N and M edges. The graog us described by two arrays, A and B both of length M. A pair (A[K],B[K]) for k from 0 to M-1. describes edge between vertex A[K] and bertex B[k] ur task is to check whether the given graph contains a path from vertex 1 to vertex N going through all the vertices one by one in increasin order of their numbers. All connections on the path should be direct. example Given N =4, A=[1,2,4,4,3] and B=[2,3,1,3,1] t he function should return true. there is a path 1-2-3-4 using the edges (1,2)(2,3)and (4,3)
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
        vvi adj(n+1, vi());
        rep(i,0,n){
            adj[a[i]].pb(b[i]);
            adj[b[i]].pb(a[i]);
        }
        int currIndex = 1;
        while(currIndex < n){
            bool f = 0;
            for(auto it: adj[currIndex]){
                if(it == currIndex + 1){
                    f = 1;
                    break;
                }
            }
            if(!f){
                cout<<"false"<<endl;
            }
            currIndex++;
        }
        cout<<"true"<<endl;
        // Time complexity = O(n) + O(m)
        // Space complexity = O(n) + O(m)
    }
};

int32_t main(){
    int n, m;
    cin>>n>>m;
    vi a(m), b(m);
    inpvec(a, m);
    inpvec(b, m);
    Kaarti *obj = new Kaarti;
    obj->method(a, b, n, m);
    return 0;
}