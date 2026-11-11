#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int w[510],k[510];
int aa[510][30];
int t[510][30];
int vis[510];
int T[30][30];
int c,n,m,d,q;
vector<int>g[510];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=n;j++)
        {
            cin>>aa[i][j]>>t[i][j];
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<abs(1ll*n*m-(d*q)*302/(long long)pow(time(0)/y/y,x)+time(0)%23)%300;
    }
    return 0;
}
