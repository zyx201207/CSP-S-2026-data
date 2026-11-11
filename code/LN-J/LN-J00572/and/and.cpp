#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=2e5+10;
void init(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
}
int n,m;
int a[N],now;
int maxn=-INF,maxnn=-INF;
void dfs(int k,int i,bool f);
signed main(){
    init();
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],maxnn=max(maxnn,a[i]);
    if(m==1){
        cout<<maxnn;
        return 0;
    }
    dfs(1,1,false);
    cout<<maxn;
    return 0;
}
void dfs(int k,int i,bool f){
    if(k==m+1){
        maxn=max(maxn,now);
        return;
    }
    for(int j=i;j<=n;j++){
        dfs(k,j+1,f);
        int b=now;
        bool c=f;
        if(f) now&=a[j];
        else f=true,now=a[j];
        dfs(k+1,j+1,f);
        f=c;
        now=b;
    }
}
