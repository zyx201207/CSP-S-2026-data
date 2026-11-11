#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],cnt[300005]={0},last[300005],sum[300005]={0};
bool vis[300005]={false};
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		last[a[i]]=i;
		sum[a[i]]++;
	}for(int i=n;i>=1;--i){
		if(vis[a[i]]) continue;
		int now=i;
		while(now<=n){
			cnt[a[now]]+=sum[a[i]];
			now=last[a[now]]+1;
		}vis[a[i]]=true;
	}for(int i=1;i<=m;++i) cout<<cnt[i]<<' ';
	return 0;
}
