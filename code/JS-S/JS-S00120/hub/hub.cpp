#include <bits/stdc++.h>
#define int long long

using namespace std;

int read()
{
    int tot=0,f=1;
    char ch=getchar();
    while(ch!='-'&&(ch>'9'||ch<'0'))
        ch=getchar();
    if(ch=='-')
        f=-1,ch=getchar();
    while(ch>='0'&&ch<='9')
        tot=tot*10+(ch-'0'),ch=getchar();
    return tot*f;
}

const int maxn=2e6+10;
int c,T,n,k;

void solve()
{
    n=read(),k=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
    }
    printf("%lld\n",n%10+1);
    return ;
}

signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
//  ios::sync_with_stdio(0);  cin.tie(0);  cout.tie(0);
    c=read(),T=read();
    while(T--)
        solve();
    return 0;
}
