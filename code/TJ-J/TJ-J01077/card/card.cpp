#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mk make_pair
bool ST;
int n,m,a[500010],b[300010],ed[300010];
vector<int> g[300010];
void dfs(int x)
{
	for(int i=0;i<g[x].size();++i)
	{
		int y=g[x][i];
		dfs(y);
		b[x]+=b[y];
	}
}
bool ED;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		b[a[i]]++;
		ed[a[i]]=i;
	}
	int root=0;
	for(int i=1;i<=m;++i)
	{
		if(ed[i]==n)root=i;
		else g[a[ed[i]+1]].pb(i);
	}
//	for(int i=1;i<=m;++i)
//	{
//		cerr<<i<<"\n";
//		for(int j=0;j<g[i].size();++j)cerr<<g[i][j]<<" ";
//		cerr<<"\n";
//	 } 
	dfs(root);
	for(int i=1;i<=m;++i)
	{
		cout<<b[i];
		if(i!=m)cout<<" ";
	}
//	cerr<<"\nTime used: "<<1.0*clock()/CLOCKS_PER_SEC*1000<<"ms\n";
//	cerr<<"Memory used: "<<abs(&ST-&ED)/1024.0/1024.0<<"mb\n";
	return 0;
}
/*
1h ak了，太闲了，写个题解。今年最后一题出难了。 

首先观察只有一个序列，不考虑后缀的情况。设序列开头的数是 $x$，那么 $x$ 最终一定会留在桌面上，而且最后一个 $x$ 之前的都会被删除。

证明的话考虑因为 $x$ 是第一个，所以没有别的数能删掉它，而且在后面再次遇到 $x$ 的时候，前面所有的都会被删除，当前这个 $x$ 又成为了第一个，所以永远会留在桌面上。

那么最后一个 $x$ 之前的就可以不用考虑了，设最后一个 $x$ 位置是 $i$，那么 $i$ 及之前就只会留下一个 $x$，又由于后面已经没有 $x$ 了，所以从 $i + 1$ 开始又是一个相同的子问题。

这启发我们记录每个数最后一次出现的位置和出现次数，把 $x$ 这个数和最后一个 $x$ 后面一个的数连边，那么我们得到了一颗树，根是整个序列的最后一个数，那么这个数的答案就是子树内的数的出现次数的和，做一个树上前缀和即可。

时间复杂度 $O(n)$。 
*/
