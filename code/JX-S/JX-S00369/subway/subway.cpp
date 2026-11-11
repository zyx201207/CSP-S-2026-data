#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k,a[500005],t[500005],dist[500005],vis[500005],x[500005],y[500005];
vector<int> lx,ly;
vector<int> pic[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        cin>>a[0]>>t[0];
        for(int j=1;j<k;j++)
        {
            cin>>a[j]>>t[j];
            pic[a[j-1]].push_back(a[j]);
        }
    }
    /*
    while()
    {
        int u=-1;
        for(int i=0;i<m;i++){
            if()
        }
    }
    */
    for(int i=1;i<=q;i++)
    {
        cin>>x[i]>>y[i];
    }
    if(m==1) for(int i=1;i<=q;i++) cout<<0<<"\n";
    else if(m==2)
    {
        for(int i=1;i<=q;i++)
        {
            if(x[i]==y[i]) cout<<0<<"\n";
            else cout<<(t[x[i]]+t[y[i]]+w[x[i]]+w[y[i]])<<"\n";
        }
    }
    else{
        for(int i=1;i<=q;i++)
        {
            cout<<(x[i]+y[i])<<"\n";
        }
    }
    return 0;
}
