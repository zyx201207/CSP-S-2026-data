#include<bits/stdc++.h>
using namespace std;
int x[2000010],n,d;
struct node
{
    int x,len;
};
bool bfs(int l,int r)
{
    queue<node>q;
    q.push({l,0});
    int mn=INT_MAX,ans=0;
    while(q.size())
    {
        node t=q.front();q.pop();
        if(t.x>=r)
        {
            if(min(mn,t.len)==t.len)ans++;
            if(ans>2)break;
            continue;
        }
        for(int i=t.x+1;i<=r;i++)
        {
            if(x[i]-x[t.x]<=d)
            {
                q.push({i,t.len+1});
            }
        }
    }
    return ans==2;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        cerr<<n<<'\n';
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                cnt+=bfs(i,j-1);
                if(bfs(i,j-1))cerr<<i<<' '<<j<<'\n';
            }
        }
        cout<<cnt<<'\n';
    }
return 0;
}
/*++rp*/
