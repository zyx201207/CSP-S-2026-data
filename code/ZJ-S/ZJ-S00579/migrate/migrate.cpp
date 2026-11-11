#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+10; 
long long n,d;
long long ans;
long long a[N];
long long l;
void arr(long long now,long long v)
{
	long long mn=1e18;
	if(now==v) return ;
	for(long long i=v;i>=now+1;i--)
		if(abs(a[i]-a[now])<=d)
		{
			l++;
			arr(i,v);
			break;
		}
}
void dfs(long long u,long long v)
{
	map<int,int> mp;
	int mn=1e9+7,ml=1e9+7;
	for(int i=v;i>=u+1;i--)
		if(abs(a[i]-a[u])<=d)
		{
			l=0;
			arr(i,v);
			mp[l]++;
			if(ml>=l) ml=l;
		}
	if(mp[ml]==2) ++ans;
}
void solve()
{
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=n-i+1;j++) dfs(j,j+i-1);
		if(ans!=0) break;
	}
	cout<<ans<<'\n';
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++) solve();
	return 0;
}
/*
至少看懂了，我是最棒的小羊
贪心暴力你们还会爱我吗？ 

暴力过了O.o
哈哈哈哈！

不是这怎么这么大啊
哎呀我*了啊 
*/
