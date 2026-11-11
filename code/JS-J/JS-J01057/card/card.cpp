#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n,m,a[300005];
int pos[300005],ans[300005];
bool vis[300005],ans1[300005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    bool f=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<a[i-1]) f=0;
    }
    if(f)
    {
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof vis);
            for(int j=i+1;j<=m;j++)
            {
                if(!vis[a[j]])
                {
                    vis[a[j]]=1;
                    ans1[a[j]]++;
                }
            }
        }
        for(int i=1;i<=m;i++) cout<<ans1[i]<<" ";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        stack<int> stk;
        for(int j=i;j<=n;j++)
        {
            if(!pos[a[j]])
            {
                stk.push(a[j]);
                pos[a[j]]=stk.size();
            }
            else
            {
                while(stk.top()!=a[j]) pos[stk.top()]=0,stk.pop();
            }
        }
        while(!stk.empty())
        {
            ans[stk.top()]++;
            pos[stk.top()]=0;
            stk.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}

