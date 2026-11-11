#include<bits/stdc++.h>
#define pr pair
#define f first
#define s second
#define mp make_pair
#define ll long long
#define pii pr<int,int>
using namespace std;
vector<pii> hd[500005];
ll ds[502][502];
ll w[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cd,n,m,dc,q;
    cin>>cd>>n>>m>>dc>>q;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i!=j) ds[i][j]=1e18;
    for(int i=0;i<m;i++) cin>>w[i];
    int h,x,y;
    for(int i=0;i<n;i++)
    {
        cin>>h;
        while(h--)
        {
            cin>>x>>y;
            x--;
            hd[x].push_back(mp(i,y));
        }
    }
    for(int i=0;i<m;i++) for(pii j:hd[i]) for(pii k:hd[i])
    {
        ds[j.f][k.f]=min(ds[j.f][k.f],0ll+j.s+k.s);
    }
    for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++)
    {
        ds[i][j]=min(ds[i][j],ds[i][k]+ds[k][j]);
    }
    while(q--)
    {
        cin>>x>>y;
        ll op=1e18;
        x--;
        y--;
        for(pii j:hd[x]) for(pii k:hd[y])
        {
            op=min(op,j.s+k.s+ds[j.f][k.f]);
        }
        cout<<op+w[x]+w[y]<<'\n';
    }
    return 0;
}
