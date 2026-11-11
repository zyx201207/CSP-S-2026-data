#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int n,m,a[N],c[N],last[N],id[N],sum[N];
void solve(int l,int r)
{
	memset(last,0,sizeof(last));
	memset(id,0,sizeof(id));
	memset(a,0,sizeof(a));
	int n=r-l+1,cnt=0;
	for(int i=l;i<=r;++i)
	{
		if(last[c[i]])
		{
			int t=last[c[i]]-1;
			for(int j=last[c[i]];j<=cnt;++j) last[id[j]]=0,id[j]=0;
			cnt=t;
		}
		a[++cnt]=c[i];
		last[c[i]]=cnt;
		id[cnt]=c[i];
	}
	for(int i=1;i<=cnt;++i) sum[a[i]]++;
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>c[i];
	for(int i=1;i<=n;++i) solve(i,n);
	for(int i=1;i<=m;++i) cout<<sum[i]<<" ";
	return 0;
}
/*
红色彼岸花，花瓣遍地撒，谁会在乎她在哭泣啊。
佛前跪千年，为见佛生怜，我好想能再见她一面。
我跨过忘川，也走过彼岸，期盼她还能够回头看。
忘川河难度，拦了她一路，佛若不度，那就由我来度。
一花一叶一菩提，轮回皆是场迷。
我待菩提落满地，看着半世烟雨……
*/ 
