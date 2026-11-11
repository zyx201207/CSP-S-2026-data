#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
typedef long long ll;

ll read() {
    ll s=0;
    char c=getchar();
    bool f=0;
    while(c<'0' || c>'9') f|=c=='-',c=getchar();
    while(c>='0' && c<='9') s=s*10+c-'0',c=getchar();
    if(f) s=-s;
    return s;
}

int T;
int n;
ll d,a[N];
pair<int,int> f[N];

int solve(int x) {
    for(int i=x+1;i<=n;i++) f[i]={n+1,0};
    f[x]={0,1};
    int res=0;
    for(int i=x;i<=n;i++) {
        f[i].second=min(3,f[i].second);
        if(f[i].second==2) res++;
        for(int j=i+1;j<=n && a[j]-a[i]<=d;j++) {
            if(f[j].first>f[i].first+1) f[j]={f[i].first+1,0};
            if(f[j].first==f[i].first+1) f[j].second+=f[i].second;
        }
    }
    return res;
}

int main() {
    freopen("data.in","r",stdin);
    freopen("bf.out","w",stdout);
    read();
    T=read();
    while(T--) {
        n=read(),d=read();
        for(int i=1;i<=n;i++) a[i]=read();
        ll ans=0;
        for(int i=1;i<=n;i++) ans+=solve(i);
        printf("%lld\n",ans);
    }
    return 0;
}
