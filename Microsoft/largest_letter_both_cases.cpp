/*
Link: https://aonecode.com/microsoft-online-assessment-questions#llb

Given a string S, find the lexically largest alphabet character, whose uppercase and lowercase both appear in S. Return the answer in uppercase.

Example:
Input
S = "CharAcTER"

Output
"R"

Input
S = "cHaracTer"

Output
"NONE"
No letter appears in both uppercase and lowercase.
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
    void method(string& s){
        vi upper(26, 0), lower(26, 0);
        for(auto it: s){
            if(it >= 'A' && it <= 'Z'){
                upper[it - 'A']++;
            } else {
                lower[it - 'a']++;
            }
        }
        for(int i=25; i>=0; i--){
            if(upper[i] > 0 && lower[i] > 0){
                cout<<char(i + 'A')<<endl;
                return;
            }
        }
        cout<<"NONE"<<endl;
    }
};

int32_t main(){
    string s;
    cin>>s;
    Kaarti *ob = new Kaarti;
    ob->method(s);
    return 0;
}