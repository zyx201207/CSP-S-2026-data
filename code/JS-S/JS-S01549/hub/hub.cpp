#include <bits/stdc++.h>
using namespace std;

const int N=4e3;

struct node
{
    int id,num;
    bool operator < (const node &a) const
    {
        return num>a.num;
    }
};

vector<int> G[N];
bool is[N];
int n,m;

int dfs(int x,int y,int k)
{
    if(k==0)
    {
        bool in[N];
        memset(in,0,sizeof(in));
        queue<node> q;
        for(int i=1; i<=n; i++)
        {
            if(is[i])
            {
                q.push({i,0});
                in[i]=1;
            }
        }
        int num=0;
        while(!q.empty())
        {
            node now=q.front();
            q.pop();
            num=max(num,now.num);
            for(int i:G[now.id])
            {
                if(!in[i])
                {
                    q.push({i,now.num+1});
                    in[i]=1;
                }
            }
            //cout<<num<<endl;
        }
        return num;
    }
    int ans=0x3f3f3f;
    for(int i:G[x])
    {
        for(int j:G[y])
        {
            if(!is[i])
            {
                is[i]=1;
                ans=min(ans,dfs(i,y,k-1));
                is[i]=0;
            }
            if(!is[j])
            {
                is[j]=1;
                ans=min(ans,dfs(x,j,k-1));
                is[j]=0;
            }
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c,T;
    cin>>c>>T;

    while(T--)
    {
        for(int i=1; i<=n; i++)
        {
            G[i].clear();
        }
        cin>>n>>m;

        for(int i=1; i<n; i++)
        {
            int x,y;
            cin>>x>>y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        if(n==m)
        {
            cout<<0<<endl;
            continue;
        }

        int ans=0x3f3f3f;
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                is[i]=1;
                is[j]=1;
                ans=min(dfs(i,j,m-2),ans);
                //cout<<dfs(i,j,m-2)<<" "<<i<<" "<<j<<endl;
                is[i]=0;
                is[j]=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
