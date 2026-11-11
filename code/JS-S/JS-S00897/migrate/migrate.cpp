#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        int ans=0;
        vector<int> v[2000005];
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(x[j]-x[i]<=d)
                    v[i].push_back(j);
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int dis=2e9,cnt=0;
                queue<pair<int,int> > q;
                q.push({i,0});
                while(!q.empty())
                {
                    int x=q.front().first,y=q.front().second;
                    q.pop();
                    if(x==j)
                    {
                        if(y<dis)
                        {
                            dis=y;
                            cnt=1;
                        }
                        else if(y==dis)
                            cnt++;
                    }
                }
                if(cnt==2)
                    ans++;
            }
        }
        cout<<ans<<"\n";
    }
}
