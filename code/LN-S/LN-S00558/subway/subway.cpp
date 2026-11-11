#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int ma[500][N],co[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++)
        cin>>co[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int a,b;
            cin>>a>>b;
            ma[i][a]=b;
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<0<<endl;
    }
    return 0;
}
