#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+5;
ll c,t,n,d,x[N],ans,b[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            b[i]=x[i]-x[i-1];
            if(b[2]*2>d)
            {
               cout<<0<<endl;
               return 0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+2;j<=n;j++)
            {
                if((x[j]-x[i])%d!=0)
                {
                    if(((j-i)%(d/b[2]))!=0)
                    {
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
