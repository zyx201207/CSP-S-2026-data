#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2*1e5+10;

int n,m;
int a[N];
bool vis[N];
int ans;

void dfs(int x){
    if(x==n+1){
        int cnt=0;
        bool boo=true;
        for(int i=1;i<=n;i++){
            if(vis[i]){
                cnt++;
            }
        }
        if(cnt!=m)return;
        int p;
        for(int i=1;i<=n;i++){
            if(vis[i]){

                if(boo==true){
                    p=a[i];
                    boo=false;
                }else{
                    p=p&a[i];
                }
            }
        }
        ans=max(ans,p);
        return;
    }
    vis[x]=false;
    dfs(x+1);
    vis[x]=true;
    dfs(x+1);
}

void solve1(){
    dfs(1);
    cout<<ans<<endl;
}

void solve2(){
    sort(a+1,a+1+n,greater<int>());
    int p=a[1];
    for(int i=2;i<=m;i++){
        p=p&a[i];
    }
    cout<<max(p,a[m]);
}

signed main(){
    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        solve1();
    }else{
        solve2();
    }
    return 0;
}

