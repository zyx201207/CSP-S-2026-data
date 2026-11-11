#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
const int N=2e6+10;
int a[N];
int c,t;
int minn=0x3f3f3f3f,ans=0;
void dfs(int x,int y,int dis){
    if(x==y){
        minn=min(minn,dis);
        return;
    }
    for(int i=x+1;i<=y;i++){
        if(a[i]-a[x]<=d)dfs(i,y,dis+1);
    }
}
void getcnt(int x,int y,int dis){
    if(x==y){
        if(minn==dis)ans++;
        return;
    }
    for(int i=x+1;i<=y;i++){
        if(a[i]-a[x]<=d)getcnt(i,y,dis+1);
    }
}
bool check(int u,int v){
    minn=0x3f3f3f3f,ans=0;
    dfs(u,v,0);
    getcnt(u,v,0);
    if(ans==2)return 1;
    else return 0;
}
void solve(){
    cin>>n>>d;
    int cnt=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(check(i,j))cnt++;
        }
    }
    cout<<cnt<<"\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    cin>>c>>t;
    while(t--)solve();
    return 0;
}
