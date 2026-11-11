#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500009],x,y,t[500009],tt[500009],k,num=1e17,ans=1e17;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=2;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>x>>y;
            if(i==1)
            {
                t[x]=y;
            }
            else
            {
                tt[x]=y;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(t[i]>0&&tt[i]>0)num=min(num,t[i]+tt[i]);
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        if(t[x]!=0&&t[y]!=0)ans=min(ans,t[x]+t[y]);
        if(tt[x]!=0&&tt[y]!=0)ans=min(ans,tt[x]+tt[y]);
        if(t[x]!=0&&tt[y]!=0)ans=min(ans,t[x]+tt[y]+num);
        if(tt[x]!=0&&t[y]!=0)ans=min(ans,tt[x]+t[y]+num);
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
