#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2*1e6+10,M=2*N;
vector<int>f[M];
int v[N],vv[N],a[N],ans[N],cnt;
void bfs(int u)
{
    queue<int>q;
    q.push(u);
    v[u]=1ll;
    ans[u]=0;
    while(q.size())
    {
        auto t=q.front();
        q.pop();
        for(auto x:f[t])
        {
            if(vv[x]==1ll){
                if((ans[t]+1ll)==ans[x]){
                    cnt++;
                }
                ans[x]=min(ans[x],ans[t]+1ll);
                if(v[x]==0)q.push(x);
                v[x]=1ll;
            }
        }
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int kkk;
    cin>>kkk;
    int bb;
    cin>>bb;
    while(bb--)
    {
        cnt=0;
        for(auto &x:f)x.clear();
        memset(a,0,sizeof a);
        memset(vv,0,sizeof vv);
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            vv[a[i]]=1;
            for(int j=a[i]-m;j<=a[i]+m;j++)
            {
                if(j==a[i])continue;
                f[a[i]].push_back(j);
            }
        }
        for(auto x:a)
        {
            for(int i=0;i<n;i++){
                v[a[i]]=0,ans[a[i]]=99999999;
            }
            bfs(x);
        }
        cout<<cnt/2<<endl;
    }
    return 0;
}
