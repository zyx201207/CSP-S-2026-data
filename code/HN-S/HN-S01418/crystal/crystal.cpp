#include<iostream>
#include<algorithm>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 5e5+5;
const int inf = 1e12+1;

int n,m,a[MAXN],d[MAXN];

int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}

bool check(int x){
    for(int i=x;i<=n;i++){
        int l=i-x+1,r=i;
        int sum= x * a[r] - ( d[r] - d[l-1] );
        // cout<<x<<' '<<l<<' '<<r<<' '<<sum<<' '<<m<<endl;
        if(sum<=m) return true;
    }
    return false;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    n=read(),m=read();
    d[0]=0;
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) d[i]=d[i-1]+a[i];
    
    int l=1,r=n,mid;
    while(l<r){
        mid=(l+r+1)>>1;
        // cout<<l<<' '<<r<<' '<<mid<<' '<<check(mid)<<endl;
        if(check(mid)) l=mid;
        else r=mid-1;
    }

    printf("%lld\n",l);
    return 0;
}