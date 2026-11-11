#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int rd(){
    int x=0;bool f=0;char c=getchar_unlocked();
    while((c<'0'||c>'9')&&c!='-')c=getchar_unlocked();
    if(c=='-')f=1,c=getchar_unlocked();
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar_unlocked();
    if(f)return -x;
    return x;
}
ll rdll(){
    ll x=0;bool f=0;char c=getchar_unlocked();
    while((c<'0'||c>'9')&&c!='-')c=getchar_unlocked();
    if(c=='-')f=1,c=getchar_unlocked();
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar_unlocked();
    if(f)return -x;
    return x;
}
int n;
ll m;
ll a[500005];
ll sum[500005];
ll dp[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=rd();m=rdll();
    for(int i=1;i<=n;i++){
        a[i]=rdll();
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int ans=0;
    int l=1;
    for(int r=1;r<=n;r++){
        while((r-l+1)*a[r]-(sum[r]-sum[l-1])>m)l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
//I love Yae Miko
//I'm yycYM(luogu uid 1411407), can you see me?;
//Last year in CSP-S, my name is yyc_Yae_Miko!
