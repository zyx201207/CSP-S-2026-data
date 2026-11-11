#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        queue<long long> q;
        for(int j=i;j<=n;j++)
        {
            if(!q.empty())
            {
                if(q.front()==a[j])
                {
                    while(1)
                    {
                        if(q.empty())   break;
                        else    q.pop();
                    }
                }
            }
            q.push(a[j]);
        }
        while(1)
        {
            if(q.empty())   break;
            else
            {
                cnt[q.front()]++;
                q.pop();
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}
