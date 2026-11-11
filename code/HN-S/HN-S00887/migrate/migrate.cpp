#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,a[N],c,t,d,tong[N];
vector<int> lu;
bool vis[N];
bool fb[N];
void dfs(int u,int kou){
    for(int i=1;i<=n;i++) fb[i]=vis[i];
    vis[u]=1;
    if(u==kou){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==1) cnt++;
        }
        tong[cnt]++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0&&abs(a[i]-a[u])<=d){
            dfs(i,kou);
        }
    }
    for(int i=1;i<=n;i++) vis[i]=fb[i];
    return ;
}
bool pan(int u,int v){
    for(int i=1;i<=n;i++) vis[i]=0;
    lu.clear();
    for(int i=0;i<=n;i++) tong[i]=0;
    dfs(u,v);
    for(int i=0;i<=n;i++){
        if(tong[i]!=0){
            if(tong[i]==2) return 1;
            else return 0;
        }
    }
    return 0;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        int cnt=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(pan(i,j)){
                    cnt++;
                    // cout<<i<<' '<<j<<endl;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
/*
g++ -o a migrate.cpp -std=c++14 -O2
time ./a
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
/*
0 1
5 2
1 2 3 4 5
*/