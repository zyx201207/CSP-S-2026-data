#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q,t1[500010];
vector<int> v1[510],v2[500010],t2[500010];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>n>>m>>q;
    cin>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>t1[i];
    }
    for(int i=1;i<=n;i++)
    {
        int tn;
        cin>>tn;
        for(int j=1;j<=tn;j++)
        {
            int t;
            cin>>t;
            v1[i].push_back(t);
            v2[t].push_back(i);
            int tx;
            cin>>tx;
            t2[t].push_back(tx);
        }
    }
    while(q--)
    {
        int st,ed;
        cin>>st>>ed;
        int ans=t1[st]+t1[ed];
        int d1=0,d2=0,ffff=0;
        for(auto i:v2[st])
        {
            for(auto j:v2[ed])
            {
                if(i==j)
                {
                    ffff=1;
                    cout<<ans+t2[st][d1]+t2[ed][d2]<<'\n';
                    break;
                }
                d2++;
            }
            if(ffff==1)
            {
                break;
            }
            d1++;
        }
        if(ffff)
        {
            continue;
        }
        int anss=1e8;
        for(auto e:v2[st])
        {
            for(auto e2:v1[e])
            {
                for(auto e3:v2[e2])
                {
                    for(auto e4:v1[e3])
                    {
                        if(e4==ed)
                        {
                            anss=min(anss,ans+t2[st][e]+t2[ed][e3]+t2[e2][e]+t2[e2][e3]);
                        }
                    }
                }
            }
        }
        cout<<anss<<'\n';
    }
    return 0;
}
