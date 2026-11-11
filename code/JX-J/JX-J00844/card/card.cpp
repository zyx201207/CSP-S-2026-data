#include<bits/stdc++.h>
using namespace std;
int a[5000010],ans[3000010];
bool mp[3000001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    stack<int>q;
    for(int i=1;i<=n;i++)
    {
        while(q.size())q.pop();
        memset(mp,0,sizeof mp);
        for(int j=i;j<=n;j++)
        {
            if(mp[a[j]])
            {
                while(q.top()!=a[j])
                {
                    mp[q.top()]=0;
                    q.pop();
                }
            }
            else
            {
                q.push(a[j]);
                mp[a[j]]=1;
            }
        }
        while(q.size())
        {
            ans[q.top()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
return 0;
}
/*++rp*/
