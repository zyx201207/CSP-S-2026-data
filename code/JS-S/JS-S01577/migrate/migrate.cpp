#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node
{
    int p,step;
};
int c,T,n,d,x[2000005];
vector<int> v[305];
int vis[305][305];
int step[305][305];
void bfs(int st)
{
    queue<Node> q;
    q.push((Node){st,0});
    while(q.size()!=0)
    {
        Node now=q.front();
        q.pop();
        if(vis[st][now.p]==0)
        {
            vis[st][now.p]=1;
            step[st][now.p]=now.step;
        }else{
            if(step[st][now.p]==now.step)
            {
                vis[st][now.p]++;
            }
        }
        for(int i=0;i<v[now.p].size();i++)
        {
            int nx=v[now.p][i];
            if(nx<now.p)
            {
                continue;
            }
            if(vis[st][nx]<=2)
            {
                q.push((Node){nx,now.step+1});
            }
        }
    }
    return;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        if(c==11||c==12)
        {
            int t=x[2]-x[1];
            int num=d/t;
            //cout<<n<<" "<<d<<" "<<t<<" "<<num<<endl;
            if(num<=1)
            {
                cout<<"0\n";
            }else{
                cout<<max(0ll,n-1-(2*num-1)+1)<<'\n';
            }
            continue;
        }
        if(c==13||c==14)
        {
            vector<int> t;
            for(int i=1;i<=n;i++)
            {
                if(x[i]-x[1]<=d&&x[n]-x[i]<=d)
                {
                    t.push_back(i);
                }
            }
            int num1=t[0]-1;
            int num2=t.size();
            int num3=n-num1-num2;
            if(num2>=2)
            {
                cout<<"0\n";
            }else{
                cout<<num1*num3<<'\n';
            }
            continue;
        }
        if(15<=c&&c<=18)
        {

        }
        for(int i=1;i<=n;i++)
        {
            v[i].clear();
            for(int j=i+1;j<=n;j++)
            {
                vis[i][j]=step[i][j]=0;
                if(x[j]-x[i]<=d)
                {
                    v[i].push_back(j);
                }else{
                    break;
                }
            }
            for(int j=1;j<=i;j++)
            {
                vis[i][j]=step[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            bfs(i);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(vis[i][j]==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
