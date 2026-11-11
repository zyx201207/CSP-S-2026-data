#include <bits/stdc++.h>

using namespace std;

int t;
int a[2000006];

int bfs(int s,int e,int d)
{
    queue<int> q;
    int i=s;
    q.push(a[i]);
    int ans=0;
    while (i<=e)
    {
        i++;
        while(a[i]-q.front()>d)
        {
            q.pop();
        }
        if(i==e)
        {
            while(!q.empty())
            {
                ans++;
                q.pop();
            }
            break;
        }
        q.push(a[i]);
    }
    return ans;
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int abcdef;
    cin>>abcdef;
    cin>>t;
    while (t--)
    {
        int n,d;
        cin>>n>>d;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                if(bfs(i,j,d)==2)
                {
                    ans++;
                }
            }
        }
        memset(a,0,n);
        cout<<ans<<endl;
    }
    return 0;
}
