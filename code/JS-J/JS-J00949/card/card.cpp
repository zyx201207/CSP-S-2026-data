#include <bits/stdc++.h>
using namespace std;
stack<int>ca;
bool f[300010];
int a[500010];
int ans[300010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++)cin>>a[i];
    for(int i= 1;i<=n;i++)
    {
        for(int j=i;j <= n;j++)
        {
            if(!f[a[j]]){
                ca.push(a[j]);
                f[a[j]]=1;
            }
            else
            {
                while(ca.top()!=a[j])
                {
                    int u=ca.top();
                    f[u]=0;
                    ca.pop();
                }
            }

        }
        while(!ca.empty())
        {
            int u=ca.top();
            f[u]=0;
            ans[u]++;
            ca.pop();
        }
    }
    for(int i = 1;i <= m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
