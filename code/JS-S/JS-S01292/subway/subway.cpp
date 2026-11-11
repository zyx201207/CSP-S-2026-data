#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[505];
vector<int> a[505];
int t[505][500005];
bool v[505];
int st,ed;
long long ans=1e18+7;
void f(int x,int dis,int ii)
{
    if(x==ed)
    {
        dis+=(t[ii][ed]+w[ed]);
        if(ans==1e18+7) ans=dis;
        else if(dis<ans) ans=dis;
        return ;
    }
    v[x]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            if(a[i][j]==x&&j<a[i].size()-1&&v[a[i][j+1]]==0)
            {
                if(i==ii) f(a[i][j+1],dis,i);
                else f(a[i][j+1],dis+t[ii][x]+t[i][x],i);
            }
        }
    }
    v[x]=0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        int x;
        for(int j=1;j<=k[i];j++)
        {
            cin>>x>>t[i][x];
            a[i].push_back(x);
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>st>>ed;
        ans=1e18+7;
        f(st,w[st],0);
        cout<<ans<<endl;
    }
    return 0;
}
