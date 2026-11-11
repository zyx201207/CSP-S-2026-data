#include <bits/stdc++.h>
using namespace std;

#define int long long

int s[500011],a[500011],n,m,ans;

inline void read(int &x){
    char c=getchar();
    int s=1;
    while(c<'0'||c>'9'){
        if(c=='-')
            s*=-1;
        c=getchar();
    }
    x=0;
    while(c>='0'&&c<='9')
        x=(x<<1)+(x<<3)+c-48,
        c=getchar();
    x*=s;
    return;
}

int calc(int x){
    int l=0,r=x+1;
    while(l+1<r){
        int mid=(l+r)/2;
        if(a[x]*(x-mid+1)-s[x]+s[mid-1]<=m)
            r=mid;
        else
            l=mid;
    }
    return x-l;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    read(n),read(m);
    for(int i=1;i<=n;i++)
        read(a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++)
        ans=max(ans,calc(i));
    printf("%lld\n",ans);
    return 0;
}
