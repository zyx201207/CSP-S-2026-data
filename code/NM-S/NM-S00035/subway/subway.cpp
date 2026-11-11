#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll nMAX=305;
const ll mMAX=500010;
const ll dMAX=25;
const ll pMAX=100010;

const ll MAXN=90005;

ll xianlu[nMAX][mMAX]={0};
ll zhanshu[mMAX][dMAX]={0}; //0->JinZhan 1~dMAX->ting-subway
ll jihua[pMAX]={0};

ll ans[MAXN][MAXN]={0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ll c,n,m,d,p;
    cin>>c>>n>>m>>d>>p;
    for(ll i=1;i<=m;i++)
    {
        cin>>zhanshu[i][0];
    }
    for(ll i=1;i<=n;i++)
    {
        ll k=0;
        cin>>k;
        for(ll j=1;j<=k;j++)
        {
            cin>>xianlu[i][j]>>zhanshu[xianlu[i][j]][i];
        }
    }
    for(ll i=1;i<=p;i++)
    {
        cin>>jihua[i];
    }


    return 0;
}
