#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q;
int s[200005];
int ans = 0;
int n,m;
bool k;
void dfs(int i,int s1,int t,int g)
{
    if(s1 == t)
    {
        ans = max(g,ans);
        return ;

    }
    if(i > n)
    {
        return ;
    }
    int p = g;
    if(s1 == 0)
    {
        p = s[i];
    }
    else
    {
        p = s[i]&p;
    }
    dfs(i+1,s1+1,t,p);
    dfs(i+1,s1,t,g);

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        int a;
        cin>>a;
        q.push(a);
    }
    int o = 0;
    for(int i = 1;i <= n;i++)
    {
        s[i] = q.top();
        q.pop();
    }
    dfs(1,0,m,0);

    cout<<ans<<endl;
    return 0;
}
