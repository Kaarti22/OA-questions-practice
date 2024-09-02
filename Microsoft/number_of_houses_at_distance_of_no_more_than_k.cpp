/*
Link: https://leetcode.com/discuss/interview-question/5100121/Microsoft-Online-Assesement-Questions-2024/

A retail store chain wants to expand into new neighborhood. To make the number of clients as largest as possible, the new branch should be at a distance of no more than K from all the houses in the neighborhood. A is the matrix of size N * M. it represents the neighborhood as a rectangular grid, in which each cell is an integer 0(an empty plot) and 1(a house) the distance between two cells is calculated as the min number of a cell borders that one has to cross to move from the source cell to target cell. it doesn't matter whether the cells on the way are empty or occupied but it doesn't allow for moving through corners. A store an b built on an empty plot. How many suitable locations are there? Ex: given K= 2 and matrix A=[[0,0,0,0][0,0,1,0][1,0,0,1]] houses are located in the cells with coordinates (2,3)(3,1) and (3,4) we can build a new store on two empty plots that are close enough to all the houses the first possible empty plot is located at(3,2) the distance to first house at(2,3) is 2. The distance to second house at (3,1) is 1 and third house at (3,4) distance is 2. The second possible empty plot is located at (3,3). The distance to the first, second and third house are 1,2,1 given the positive integer K and matrix A of size N*M return the number of empty plots close enough to all the houses Ex: K=2 A=[[0,0,0,0][0,0,1,0][1,0,0,1]] function should return 2.
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
    vvi dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    void method(vvi &v, int n, int m, int k){
        vvi ans(n, vi(m, 0));
        int ones = 0;
        rep(i,0,n){
            rep(j,0,m){
                if(v[i][j] == 1){
                    ones++;
                    vvi vis(n, vi(m, 0));
                    queue<pair<int, int>>q;
                    q.push({i, j});
                    vis[i][j] = 1;
                    int count = 1;
                    while(!q.empty() && count <= k){
                        int size = q.size();
                        rep(i,0,size){
                            int x = q.front().first, y = q.front().second;
                            q.pop();
                            for(auto d: dir){
                                int newX = x + d[0], newY = y + d[1];
                                if(newX >=0 && newX < n && newY >= 0 && newY < m && vis[newX][newY] == 0 && v[newX][newY] == 0){
                                    ans[newX][newY]++;
                                    q.push({newX, newY});
                                    vis[newX][newY] = 1;
                                }
                            }
                        }
                        count++;
                    }
                }
            }
        }
        int res = 0;
        rep(i,0,n){
            rep(j,0,m){
                if(ans[i][j] == ones){
                    res++;
                }
            }
        }
        cout<<res<<endl;
    }
};

int32_t main(){
    int k;
    cin>>k;
    int n, m;
    cin>>n>>m;
    vvi v(n, vi(m));
    rep(i,0,n){
        rep(j,0,m){
            cin>>v[i][j];
        }
    }
    Kaarti *ob = new Kaarti;
    ob->method(v, n, m, k);
    return 0;
}