#include<bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar_unlocked();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c-'0');
        c=getchar_unlocked();
    }
    return x*f;
}
int n,m;
int a[N];
int maxn=-6666666;
int ans;
void dfs(int x,int i,int k,int go){
    if(k==m+1||i==n+1){
        if(k==m+1) maxn=max(maxn,ans);
        return;
    }
    if(k==1) ans=a[x];
    if(go) ans=ans&a[i];
    dfs(x,i+1,k+1,1);
    dfs(x,i+1,k,0);
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=n;i++){
        ans=a[i];
        dfs(i,i,1,1);
    }
    printf("%lld",maxn);
    return 0;
}
//11:30
//fk,what is it
//i do it for over 2h
//but only 25 pts
//how to get 1=
