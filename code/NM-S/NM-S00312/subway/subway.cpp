#include<bits/stdc++.h>
using namespace std;
struct l{
    int x,y,t1;
};
long long n,m,i,j,c,d,p,t[510],k,x,y,a[510][510],ans=INT_MAX;
l o;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(i=1;i<=m;i++)
    {
        cin>>t[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>k;
        for(j=1;j<=k;j++)
        {
            cin>>x>>y;
            a[i][x]=y;
        }
    }
    queue<l> q;
    while(p--)
    {
        cin>>x>>y;
        if(x>y)
        {
            swap(x,y);
        }
        q.push({x,x+1,t[x]});
        while(!q.empty())
        {
            o=q.front();
            q.pop();
            for(i=1;i<=n;i++)
            {
                if(a[i][o.x]!=0&&a[i][y]!=0)
                {
                    ans=min(ans,o.t1+a[i][o.x]+a[i][y]+t[y]);
                }
                else if(a[i][o.x]!=0&&a[i][o.y]!=0)
                {
                    if(o.y==y)
                    {
                        ans=min(ans,o.t1+a[i][o.x]+a[i][o.y]+t[y]);
                    }
                    else
                    {
                        q.push({o.y,o.y+1,o.t1+a[i][o.x]+a[i][o.y]});
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
