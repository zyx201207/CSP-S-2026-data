#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;

int als[N],sz[N],isd[N],power,n;

void bfs(int d)
{
    queue<pair<int,int>>q;
    q.push({d,0});
    als[d]=1;
    while(q.size())
    {
        pair<int,int> p=q.front();
        q.pop();
        for(int i=p.first+1;i<=n&&isd[i]-isd[p.first]<=power;i++)
        {
            if(!sz[i]||p.second+1<=sz[i])
            {
                if(p.second+1<sz[i])als[i]=1,sz[i]=p.second+1;
                else als[i]+=1;
                q.push({i,p.second+1});
            }
        }
    }
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;
    for(t;t;t--)
    {
        memset(als,0,sizeof(als));
        cin>>n>>power;
        for(int i=1;i<=n;i++)cin>>isd[i];
        bfs(1);
        int ans=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(als[j]&&als[i]&&als[j]/als[i]==2)ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}