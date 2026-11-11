#include<bits/stdc++.h>
#define rep(i,m,n) for(int i=m;i<=n;i++)
#define mem(s,t) memset(s,t,sizeof s)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N=2e6+5;
int n,d,m,x[N],cnt,ans;
void dfs(int v,int now,int t)
{
	if(t>m)return;
	rep(i,now,v)
	{
		if(x[i]-x[now]>d)break;
		if(i==v)
		{
			cnt++;
			return;
		}
		dfs(v,i,t+1);
	}
	return;
}
void solve()
{
	cin>>n>>d;
	ans=0;
	rep(i,1,n)cin>>x[i];
	rep(i,1,n)
		rep(j,1,i-1)
			cnt=0,m=(x[i]-x[j]+d)/d,dfs(i,j,1),ans+=(cnt==2)?1:0;
	cout<<ans<<endl;
	return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
    return 0;
}
