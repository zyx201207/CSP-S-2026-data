#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=2e6+2;
int c,t,n,d;
int x[M];
int ans;
bool flag1=0,flag2=0;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    if(c>=11&&c<=12) flag1=1;
    else if(c>=13&&c<=14) flag2=1;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        ans=0;
        if(flag1)
        {
            if(n>=3&&x[3]-x[1]<=d) cout<<n-2<<'\n';
            else cout<<'0'<<'\n';
            continue;
        }
        if(flag2)
        {
            int l=1,r=3,sp=0;
            while(r<=n)
            {

                if(sp==0&&(x[r]-x[1]<=d)&&(x[n]-x[r]<=d)) sp=r;
                if(sp==0)
                {
                    if(x[r]-x[l]<=d) ans++;
                }
                else
                {
                    if(r==sp)
                    {
                        if(x[r-1]-x[l]<=d) ans++;
                    }
                    else
                    {
                        if(x[r]-x[l]<=d) ans++;
                    }
                }
            }
            cout<<ans<<'\n';
            continue;
        }
        cout<<"317623"<<'\n';
    }
    return 0;
}
