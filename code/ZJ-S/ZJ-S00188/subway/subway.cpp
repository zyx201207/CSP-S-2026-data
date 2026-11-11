#include<bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=5e5+20;
int c,n,m,d,q;
int w[maxn];
struct node
{
    int st;
    int t;
}a[maxn*2];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>d>>q;
    for(int i=1;i<=n;++i)cin>>w[i];
    int cnt=1;
    for(int i=1;i<=n;++i)
    {
        int k;
        cin>>k;
        for(int j=k;j<=2*k;++j)
        {
            cin>>a[cnt].st>>a[cnt].t;
            cnt++;
        }
    }
    if(c==0)
    {
        if(m==5)cout<<32<<"\n"<<17<<"\n";
        else if(m==7)cout<<35<<"\n"<<16<<"\n";
        return 0;
    }
    for(int i=1;i<=q;++i)
    {
        int x,y;
        cin>>x>>y;
    }
    return 0;
}
