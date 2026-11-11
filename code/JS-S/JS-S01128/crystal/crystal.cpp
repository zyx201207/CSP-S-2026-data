#include<bits/stdc++.h>
#define ll long long
#define mxn 500003
#define md 998244353
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rept(i,a,b) for(int i=(a);i<(b);++i)
#define drep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
inline ll read(){
    ll x=0;bool fl=0;char c=getchar();
    while(!isdigit(c)){if(c=='-')fl=1;c=getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return fl?-x:x;
}
int n,ans;
ll m,a[mxn];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    rep(i,1,n)a[i]=read();
    sort(a+1,a+n+1);
    ll s=0;
    int l=1;
    rep(i,1,n){
        s+=a[i];
        while(a[i]*(i-l+1)-s>m)s-=a[l],l++;
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}