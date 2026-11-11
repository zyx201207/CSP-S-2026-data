#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],n,m,ans[N],f[N],c[N];
vector<int>b[N];
bool cmp(int x,int y)
{
	return b[x][b[x].size()-1]<b[y][b[y].size()-1];
}
void solve()//100pts
{
	for(int i=1;i<=n;i++)
		b[a[i]].push_back(i);
	for(int i=1;i<=m;i++)
		f[i]=b[i].size();
	for(int i=1;i<=m;i++)
		c[i]=i;
	sort(c+1,c+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		ans[c[i]]+=f[c[i]];
		f[a[b[c[i]][b[c[i]].size()-1]+1]]+=f[c[i]];
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
}
signed main()
{
 	freopen("card.in","r",stdin);
 	freopen("card.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	solve();
 	return 0;
}
