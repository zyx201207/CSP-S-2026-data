#include<bits/stdc++.h>
#define int long long
using namespace std;

int c,t;
vector<int> x;
signed main(void)
{
    freopen("migrate.out","w",stdout);
    freopen("migrate.in","r",stdin);
    cin>>c>>t;

    if(c==11||c==12||c==0)
    {
        while(t--)
        {
            x.clear();
            int n,d;
            cin>>n>>d;
            bool is0=0;
            int whereis0=0;
            for(int i=0;i<n;i++)
            {
                int b=0;
                cin>>b;
                x.emplace_back(b);
                if(b==0)
                {
                    is0=1;
                    whereis0=i;
                }
            }
                


            if(d<=(x[1]-x[0]))
            {
                cout<<0<<endl;
                continue;
            }
            int lanbada=d%abs(x[1]-x[0]);
            int ans=n-lanbada-2;
            int sizes=x.size();
            if(is0&&(sizes-1-whereis0)>lanbada+2)
            {
                ans--;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}