#include<bits/stdc++.h>
using namespace std;
int n,m,ans,x[200010],maxv=INT_MIN,fa;
bool f[200010];
bool cmp(int a,int b)
{
    return a>b;
}
void dfs(int dep,int cur)
{
    // cerr<<dep<<':'<<fa<<' '<<cur<<' '<<maxv<<endl;
    if(dep==m+1){maxv=max(maxv,cur);return;}
    if(cur<=maxv)return;
    for(int i=1;i<=n;++i)
    // {
        if(!f[i])/*cerr<<"success\n",*/fa=x[i],f[i]=true,dfs(dep+1,(dep==m?cur:cur&x[i])),f[i]=false;
        // else cerr<<"uh oh\n";
    // }
    // cerr<<'\n';
}
void solve1()
{
    dfs(0,INT_MAX);
    cout<<maxv;
    exit(0);
}
void solve2()
{
    sort(x+1,x+1+n,cmp);
    cout<<x[m];
    exit(0);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>x[i];
    if(n<=2000)solve1();
    else solve2();
}
