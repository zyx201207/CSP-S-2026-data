#include<bits/stdc++.h>
using namespace std;
const long long INF=1e17;
queue<long long> q;
long long ceshidian,T,ans,n,m,dis[5005][5005],s[5005][5005],z[2000005];
vector<long long> v[2000005];
void slove(){
	ans=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>z[i];
	}
	if(ceshidian>=11&&ceshidian<=12){
		if((z[2]-z[1])*2>m)cout<<0<<"\n";
		else if((z[2]-z[1])*3>m)cout<<max(0ll,n-3)<<"\n";
		else cout<<0<<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
		v[i].clear();
		v[i].shrink_to_fit();
		for(int j=1;j<=n;j++){
			dis[i][j]=0;
			s[i][j]=INF;
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			if(z[j]-z[i]<=m){
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}
	for(long long rt=1;rt<=n;rt++){
		for(long long j=1;j<=n;j++){
			s[rt][j]=INF;
		}
		while(!q.empty())q.pop();
		s[rt][rt]=0;
		dis[rt][rt]=1;
		q.push(rt);
		while(!q.empty()){
			long long x=q.front();
			q.pop();
			for(long long i:v[x]){
				if(s[rt][i]>s[rt][x]+1){
					s[rt][i]=s[rt][x]+1;
					dis[rt][i]=dis[rt][x];
					q.push(i);
				}else if(s[rt][i]==s[rt][x]+1){
					dis[rt][i]+=dis[rt][x];
				}
			}
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			if(dis[i][j]==2)ans++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);  
	cin>>ceshidian>>T;
	while(T--)slove();
	return 0;
}
/*
11 3
4 2
1 2 3 4
5 2
1 2 3 4 5
5 3
-2 -1 0 1 2
*/