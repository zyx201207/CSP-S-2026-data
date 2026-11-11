#include<bits/stdc++.h>
using namespace std;
int c,t;
const int N=2e6+10;
vector<int>e[N];
long long x[N];
int minn[N];
int cnt[N];
bool f[N];
void bfs(int x)
{
    queue<pair<int,int>>q;
    f[x]=1;
    minn[x]=0;
    cnt[x]=1;
    q.push({x,0});
    while(!q.empty())
    {
        int len=q.front().second;
        int u=q.front().first;
        q.pop();
        for(int to:e[u])
        {
            if(!f[to])
            {
                minn[to]=len+1;
                cnt[to]=1;
                f[to]=1;
                //cout<<to<<"\n";
                q.push({to,minn[to]});
                continue;
            }
            if(len+1==minn[to])
            {
                q.push({to,minn[to]});
                cnt[to]++;
                continue;
            }
            if(len+1<minn[to])
            {
                minn[to]=len+1;
                cnt[to]=1;
                //cout<<to<<"\n";
                q.push({to,minn[to]});
            }
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        int n;
        long long d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            for(int j=1;j<i;j++)
            {
                //cout<<llabs(x[i]-x[j])<<"\n";
                if(llabs(x[i]-x[j])<=d)
                {
                    //cout<<i<<" "<<j<<"\n";
                    e[i].push_back(j);
                    e[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            memset(minn,0,sizeof(minn));
            memset(f,0,sizeof(f));
            memset(cnt,0,sizeof(cnt));
            bfs(i);
            for(int j=i+1;j<=n;j++)
            {
                //if(cnt[j]==2)
                //{
                    //cout<<i<<" "<<j<<" "<<minn[j]<<"\n";
                //}
                ans+=(cnt[j]==2);
            }
        }
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++)
        {
            e[i].clear();
        }
    }
    return 0;
}
