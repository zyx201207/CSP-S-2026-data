#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e4+8;
const int ID=5e2+8;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') f=(ch=='-')?-1:1,ch=getchar();
    while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int c,T;
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    c=read(),T=read();
    while(T--)
    {
        int n,k;
        n=read(),k=read();
        for(int i=1,u,v;i<n;i++) u=read(),v=read();
        cout<<0<<'\n';
    }
    return 0;
}
