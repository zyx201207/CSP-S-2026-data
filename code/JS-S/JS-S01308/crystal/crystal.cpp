#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
inline int read(){
    int x=0;
    bool b=1;
    char c=getchar_unlocked();
    while(c<'0'||c>'9'){
        if(c=='-')b=0;
        c=getchar_unlocked();
    }while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar_unlocked();
    }return b?x:~(x-1);
}int n,m,a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    int ans=0,l=n,s=m;
    while(a[n]-a[l-1]<=s&&l>1)s-=a[n]-a[--l];
    ans=n-l+1;
    for(int i=n-1;i>ans;i--){
        s+=(a[i+1]-a[i])*(i-l+1);
        while(a[i]-a[l-1]<=s&&l>1)s-=a[i]-a[--l];
        ans=max(ans,i-l+1);
    }
    printf("%lld\n",ans);
    return 0;
}