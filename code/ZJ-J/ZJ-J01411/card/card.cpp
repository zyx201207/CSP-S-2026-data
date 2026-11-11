#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],d[300005],cnt[300005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int l=i;
		while(l<=n){
			cnt[a[l]]++;
			l=d[a[l]]+1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
/*
( ^_^ )
( qwq )
dfs("I can't do this problem");
bfs("Me too);
spfa("kskbl");
dijist("zdjd");
trie("letsgo");
*/
