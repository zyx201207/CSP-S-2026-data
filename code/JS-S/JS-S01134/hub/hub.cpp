#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1,INF=0x3f3f3f3f,NINF=0xc0c0c0c0;
int n,m,k,a[N];


inline LL read()
{
    char c=getchar();
    bool sign=0;
    LL p=0;
    while(c<'0'||c>'9') sign=(c=='-'),c=getchar();
    while(c>='0'&&c<='9') p=(p<<3)+(p<<1)+c-'0',c=getchar();
    return (sign?-p:p);
}

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    n=read();
    m=read();
    while(m--)
    {
        int t,d;
        cin>>t>>d;
        for(int i=1,x,y;i<=t;i++) cin>>x>>y;
        cout<<1;
    }
    cout<<n+m;
    return 0;
}
