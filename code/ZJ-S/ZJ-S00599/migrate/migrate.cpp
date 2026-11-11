#include<bits/stdc++.h>
using namespace std;
long long c,t,cnt,mi,n,d,a[2000010];
vector<int> mp[2000010];
bool vis[2000010];
void dfs(int x,int y,int step) {
	if(x==y) {
		if(step<mi)
			mi=step,cnt=1;
		else if(step==mi)
			cnt++;
		return;
	}
	for(int i=0; i<mp[x].size(); i++) {
		int v=mp[x][i];
		if(vis[v])
			continue;
		vis[v]=true;
		dfs(v,y,step+1);
		vis[v]=false;
	}
}
void s() {
	int ans=0;
	cin>>n>>d;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			if(a[j]-a[i]<=d) {
				mp[i].push_back(j);
				mp[j].push_back(i);
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			cnt=0;
			mi=1e9;
			dfs(i,j,0);
			if(cnt==2)
				ans++;
		}
	}
	cout<<ans<<"\n";
	for(int i=1; i<=n; i++)
		while(mp[i].size())
			mp[i].pop_back();
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
		s();
	fclose(stdin);
	fclose(stdout);
	return 0;
}