#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],s[1000005],maxx;
void dfs(int m,int step)
{
    if(step>n)
    {
        int b[100005]={},ma=0;
        for(int i=1;i<=n;i++) b[a[i]]++;
        for(int i=1;i<=105;i++) ma=max(ma,b[i]);
        maxx=max(maxx,ma);
    }
    for(int i=1;i<=m;i++)
    {
        a[i]+=i;
        dfs(m-i,step++);
        a[i]-=i;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(m,1);
    cout<<maxx;
    return 0;
}
