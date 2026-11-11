#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
long long n,d;
long long x[N];
long long dis[N][N];
long long cnt[N][N];
vector<long long>g[N];
void dfs(long long x,long long sum,long long st,long long ed){
	if(x==ed){
		if(sum<dis[st][ed]){
			dis[st][ed]=sum;
			cnt[st][ed]=1;
		}else if(dis[st][ed]==sum){
			cnt[st][ed]+=1;
		}
		return ;
	}
	for(auto i:g[x]){
		dfs(i,sum+1,st,ed);
	}
}
void ac(){
	memset(dis,0x3f,sizeof dis);
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;i++)g[i].clear();
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(x[i]-x[j]<=d)g[j].push_back(i);
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dfs(i,0,i,j);
			if(cnt[i][j]==2)ans++;
		}
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)ac();
	fclose(stdin);
	fclose(stdout);
	return 0;
}