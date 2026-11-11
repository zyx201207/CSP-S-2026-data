#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
int c,T;
int n,k;
void init () {
    n=read();
    k=read();
    int u,v;
    for (int i=1;i<=n-1;i++) {
        u=read();
        v=read();
    }
}
void work () {
    int g=0;
    if (k%2==1) g++; 
    if (((n+1)/2-k)/4*4!=((n+1)/2-k)) g++;
    else cout<<((n+1)/2-k)/4+1+g%2<<'\n';
}
signed main () {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read();
    T=read();
    while (T--) {
        init();
        work();
    }
    return 0;
}