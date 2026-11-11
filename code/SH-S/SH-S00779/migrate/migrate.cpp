#include <bits/stdc++.h>
using namespace std;
int c,t;
int dis[5010];
int x[5010];
vector<int> g[5010];
int in[5010],out[5010];
int g1[5010][5010];
int dp[5010];
bool f[5010];
void solve(){
	long long n,d,ans=0;
	cin>>n>>d;
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		cin>>x[i];
		f[i]=0;
		dp[i]=0;
		g[i].clear();
	}
	dis[1]=1;
	for(int i=1;i<=n;i++){
		if(dis[i]==0x3f3f3f3f)dis[i]=1;
		for(int j=1;j<=n;j++){
			
			if(abs(x[i]-x[j])<=d)dis[j]=min(dis[j],dis[i]+1);
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			
			if(abs(x[i]-x[j])<=d and dis[j]==dis[i]+1){
				g[i].push_back(j);
				g1[i][j]++;
				out[i]++;
				in[j]++;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g1[i][j]=max(g1[i][j],g1[i][k]|g1[k][j]);
			}
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(!in[i]){
			dp[i]=1;
			q.push(i);
		}
		if(in[i]==2){
			f[i]=1;
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int v:g[x]){
			dp[v]+=dp[x];
			in[v]--;
			if(in[v]==0)q.push(v);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(g1[i][j] and f[j] and dis[j]!=dis[i]+1){
				ans++;
			}
		}
		
	}
	cout<<ans<<endl;
}
int main(){
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
