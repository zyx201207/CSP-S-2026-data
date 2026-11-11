#include <bits/stdc++.h>
using namespace std;
#define int long long
int read () {
    int s=0,f=1;
    char c=getchar();
    while ((c<'0'||c>'9')&&c!='-') c=getchar();
    if (c=='-') {
        f=-1;
        c=getchar();
    }
    while (c>='0'&&c<='9') {
        s=s*10+(c-'0');
        c=getchar();
    }
    return s*f;
}
int n,m;
int a[500001],sum[500001];
void init () {
    n=read();
    m=read();
    for (int i=1;i<=n;i++) {
        a[i]=read();
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) {
        sum[i]=sum[i-1]+a[i];
    }
}
bool check (int x,int l) {
    //cout<<l<<' '<<x<<' '<<(x-l+1)*a[x]-sum[x]+sum[l-1];
    if (((x-l+1)*a[x]-sum[x]+sum[l-1])<=m) {
        //cout<<" ok\n";
        return 1;
    }
    else {
        //cout<<" no\n";
        return 0;    
    }   
}
int bin_serach (int x) {
    int l=1,r=x;
    while (l<r) {
        int mid=(l+r)>>1;
        bool t=check(x,mid);
        if (t==1) r=mid;
        else l=mid+1;
    }
    return x-l+1;
}
void work () {
    //cout<<a[1]<<' '<<a[2]<<' '<<sum[0]<<' '<<sum[1]<<' '<<sum[2]<<'\n';
    int res=-1;
    for (int i=1;i<=n;i++) {
        res=max(res,bin_serach(i));
    }
    cout<<res<<'\n';
}
signed main () {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    init();
    work();
    return 0;
}