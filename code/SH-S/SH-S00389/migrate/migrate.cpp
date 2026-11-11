#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d,x[2100000],dis[210000],cnt[210000],ans;
vector<int>sons[2100000];
void dfs(int pos,int tar){
	if(pos==tar){
		cnt[dis[tar]]++;
		return;
	}
	for(int son:sons[pos]){
		dis[son]=min(dis[son],dis[pos]+1);
		dfs(son,tar);
	}
	return;
}
bool chk(int a,int b){
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;i++)dis[i]=INT_MAX;
	dis[a]=0;
	dfs(a,b);
	for(int i=1;i<=n;i++){
		if(!cnt[i])continue;
		if(cnt[i]!=2)return 0;
		if(cnt[i]==2)return 1;
	}
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)sons[i].clear();
		for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)if(x[j]-x[i]<=d)sons[i].push_back(j);
		for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)if(chk(i,j))ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
