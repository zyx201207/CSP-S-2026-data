#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
typedef long long LL;
LL a[N];
LL cdq(int l,int r)
{
	if(l == r) return 0;
	LL res = 0;
	int mid = l + r >> 1;
	res += cdq(l,mid);
	res += cdq(mid + 1,r);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int id,t;
	cin>>id>>t;
	while(t --)
	{
		LL n,m;
		cin>>n>>m;
		for(int i = 1; i <= n; i ++) cin>>a[i];
		cout<<cdq(1,n)<<'\n';
	}
	return 0;
}
//bf
//f[i][j]表示i到j最短路径长度，辅助g[i][j]记录条数
//i,j中存在一个k，满足 
