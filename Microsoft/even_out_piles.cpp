/*
Link: https://aonecode.com/microsoft-online-assessment-questions#eop

You are given N piles of boxes. ALl boxes are the same size. Piles[i] is number of boxes stacked in pile i. For each step, you can remove boxes from the highest pile to make it equal to the pile that is just lower than the highest one. Determine the minimum number of steps required to make all of the piles equal in height. 

Example:
Input
piles = [5, 2, 1]

Output
3

Step 1: reducing 5 -> 2 [2, 2, 1]
Step 2: reducing 2 -> 1 [2, 1, 1]
Step 3: reducing 2 -> 1 [1, 1, 1]
So final number of steps required is 3.

Input
piles = [2, 5, 10, 10]

Output
5

Step 1: reducing 10 -> 5 [2, 5, 5, 10]
Step 2: reducing 10 -> 5 [2, 5, 5, 5]
Step 3: reducing 5 -> 2 [2, 2, 5, 5]
Step 4: reducing 5 -> 2 [2, 2, 2, 5]
Step 5: reducing 5 -> 2 [2, 2, 2, 2]
So final number of steps required is 5.
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
    void method(vi &v, int n){
        map<int, int>mp;
        for(auto it: v){
            mp[it]++;
        }
        int sum = 0;
        int prev = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it == mp.begin()) continue;
            sum += ((it->second) * (prev + 1));
            prev++;
        }
        cout<<sum<<endl;
    }
};

int32_t main(){
    int n;
    cin>>n;
    vi v(n);
    inpvec(v, n);
    Kaarti *ob = new Kaarti;
    ob->method(v, n);
    return 0;
}