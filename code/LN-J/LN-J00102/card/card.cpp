#include<bits/stdc++.h>
using namespace std;
int post[500005],ans[300005],cur[300005],a[500005],n,m;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
        cin>>a[i];
    reverse(a+1,a+n+1);
    for(int i = 1;i <= m;i++)cur[i]=n+1;
    for(int i = n;i >= 1;i--)
    {
        post[i]=cur[a[i]];
        cur[a[i]]=i;
    }
    priority_queue<int,vector<int>,greater<int>>pq;//小根堆
    pq.push(post[1]);
    int i = 2;
    ans[a[1]]=n;
    while(!pq.empty())
    {
        if(i==n+1)break;
        if(i==pq.top())
            pq.pop();
        if(post[i]!=pq.top()&&i<=n)
            pq.push(post[i]);
        if(a[i]!=a[1])ans[a[i]]+=pq.top()-i;
        i++;
    }
    for(int i = 1;i <= m;i++)cout<<ans[i]<<" ";
    return 0;
}

