#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],n,m;
int f[N],lst[N];
int fst[N],cnt[N],sum[N][2];
int ans[N];
bool vis[N],fg[N];
vector<int>st[N];
int ct[3005][3005];
void dfs(int t){
	fg[t]=true;
	for(auto v:st[t]){
		if(fg[v]||!cnt[v])continue;
		dfs(v);
	}
	return;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(lst[a[i]]==0)fst[a[i]]=i,lst[a[i]]=i;
		f[i]=lst[a[i]];
		lst[a[i]]=i;
		cnt[a[i]]++;
//		sum[a[i]][cnt[a[i]]%2]+=(i-f[i]+1);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)vis[j]=false;
		for(int j=fst[i];j<=lst[i];j++){
			vis[a[j]]=!vis[a[j]];
		}
		for(int j=1;j<=m;j++){
			if(vis[j]==true)st[i].push_back(j);
		}
	}
	for(int i=1;i<=m;i++)vis[i]=cnt[i]%2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)if(vis[j]&&cnt[j]%2)ans[j]++;
//		for(int j=1;j<=m;j++)cout<<ans[j]<<' ';
//		cout<<'\n';
		vis[a[i]]=!vis[a[i]];cnt[a[i]]--;
		dfs(a[i]);
		for(int j=1;j<=m;j++)fg[j]=false;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}