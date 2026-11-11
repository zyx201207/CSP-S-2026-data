#include<bits/stdc++.h>
using namespace std;
int a[511111];
int f[511111];
int ans[511111];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=m;j++)
            f[j]=0;
        queue<int> q;
        for(int j=i;j<n;j++)
        {
            q.push(a[j]);
            if(f[a[j]])
            {
                q.pop();
                while(q.front()!=a[j])
                {
                    f[q.front()]=0;
                    q.pop();
                }
            }
            f[a[j]]=1;
        }
        while(!q.empty())
        {
            ans[q.front()]++;
            q.pop();
        }  
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    return 0;
}