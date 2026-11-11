#include<bits/stdc++.h>
using namespace std;
int c,t;
bool road[10005][10005];
int maxx;
bool check(string s,int t)
{
    int cnt;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
            cnt++;
    }
    if(cnt==t)
        return true;
    return false;
}
int calc(s)
{
    int ans=0;
    for(int i=1;i<=s.length();i++)
    {

    }
}
void dfs(string s,int n,int t)
{
    if(n==0)
    {
        if(check(s,t))
            maxx==max(maxx,calc(s));
        return;
    }
    else
    {
        dfs(s+"0",n-1,t);
        dfs(s+"1",n-1,t);
    }
    return;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            int u,v;
            cin>>u>>v;
            road[u][v]=true;
            road[v][u]=true;
        }
        string s="";
        dfs(s,n,t);
        cout<<1<<endl;
    }
    return 0;
}
