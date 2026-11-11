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
int nxt[N],pre[N];
int f[N],g[N];

int main() {
    freopen("data.in","r",stdin);
    freopen("my.out","w",stdout);
    read();
    T=read();
    while(T--) {
        n=read(),d=read();
        for(int i=1;i<=n;i++) a[i]=read();
        for(int i=1;i<=n;i++) {
            nxt[i]=max(nxt[i-1],i);
            while(nxt[i]<n && a[nxt[i]+1]-a[i]<=d) nxt[i]++;
        }
        for(int i=1;i<=n;i++) {
            pre[i]=max(pre[i-1],1);
            while(a[i]-a[pre[i]]>d) pre[i]++;
        }
        for(int i=1;i<n;i++) {
            f[i]=pre[i+1]-pre[i];
            if(pre[i]<i && nxt[pre[i]]==i) f[i]+=f[pre[i]];
        }
        for(int i=n;i>1;i--) {
            g[i]=nxt[i]-nxt[i-1];
            if(nxt[i]>i && pre[nxt[i]]==i) g[i]+=g[nxt[i]];
        }
        ll ans=0;
        for(int i=2;i+1<n;i++) {
            int cp=0,cs=0;
            if(pre[i+1]<i && nxt[pre[i+1]]==i+1) {
                cp=min(pre[i+2],i)-pre[i+1];
                if(pre[i]==pre[i+1]) cp+=f[pre[i]];
            }
            if(nxt[i]>i+1 && pre[nxt[i]]==i) {
                cs=nxt[i]-max(nxt[i-1],i+1);
                if(nxt[i]==nxt[i+1]) cs+=g[nxt[i]];
            }
            ans+=1ll*cp*cs;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//15:23