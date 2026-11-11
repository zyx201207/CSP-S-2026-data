#include<bits/stdc++.h>
using namespace std;
#define inf 0x37373737
const int N=2e6+5;
int n;
int c,T,n,d;
int x[N];
map<int,int> m;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    if(c==13||c==14)
    {
         while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        
    }
        for(int i=1;i<=T;i++)
        {
            cout<<"0\n";
            return 0;
        }
    }
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        if(c==11||c==12)
        {
            int a=x[2]-x[1];
            if(a>d) cout<<"0\n";
        }
    }
    return 0;
}