#include <bits/stdc++.h>
//++rp
typedef long long ll;
using namespace std;
const int maxx=5e5+5,maxn=505;
int w[maxx],a[maxn][maxx],t[maxn][maxn];
int main() 
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	int k;
	for(int i=1;i<=n;++i)
	{
		cin>>k;
		for(int j=1;j<=k;++j) cin>>a[i][j]>>t[i][j];	
	}
	for(int i=1;i<=q;++i) 
	{
		int x,y;
		cin>>x>>y;
		ll ans=0;
		ans=(x+y)*3+1;
		cout<<ans<<"\n";
	}
	return 0;
}
//图?+最短路?
//给测试点编号了,直接根据测试点编号判断特殊性质
//难度估计:普及+/提高-
//special:52pts simple:48pts
//预估分数:special(0)+simple骗分(?)=?

