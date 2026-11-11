#include <bits/stdc++.h>
using namespace std;
int n,m,flag[300005],a[300005],cnt[300005],last[300005];
void solve()
{
    for(int i=1;i<=n;i++)last[a[i]]=i;
    for(int i=1;i<=m;i++)cout<<last[i]<<' ';
    exit(0);
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n>500)solve();
    for(int i=1;i<=n;i++)
    {
        memset(flag,0,sizeof(flag));
        stack<int>stk;
        for(int j=i;j<=n;j++)
        {
            if(!flag[a[j]])stk.push(a[j]),flag[a[j]]=1;
            else {while(stk.top()!=a[j])flag[stk.top()]=0,stk.pop();}
        }
        while(!stk.empty())cnt[stk.top()]++,stk.pop();
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
    return 0;
}
