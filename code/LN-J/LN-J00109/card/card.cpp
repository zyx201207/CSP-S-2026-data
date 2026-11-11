#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5+10;

ll n,m;
ll a[maxn];
ll ans[maxn];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int t=1;t<=n;t++)
    {
        vector<ll> v;
        for(int i=t;i<=n;i++)
        {
            //for(auto x : v) cout << x << " ";
            //cout << "\n";
            for(auto x : v)
            {
                if(x==a[i])
                {
                    ll inx=v.size()-1;
                    while(v[inx]!=a[i]&&inx>=0&&!v.empty())
                    {
                        //for(auto x : v) cout << x << " ";
                        //cout << "\n";
                        v.pop_back();
                        inx--;
                        //for(auto x : v) cout << x << " ";
                        //cout << "\n";
                    }
                    v.pop_back();
                    //for(auto x : v) cout << x << " ";
                    //cout << "\n";
                }
            }

            v.push_back(a[i]);
        }
        for(auto x : v) ans[x]++;
    }

    for(int i=1;i<=m;i++) cout << ans[i] << " ";


    return 0;
}
/*
2023/08/23 - 2026/10/31
Aetherius AFO
cout << "Bye World!";
Q.E.D
*/
