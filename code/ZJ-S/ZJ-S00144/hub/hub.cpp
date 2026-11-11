#include<bits/stdc++.h>
using namespace std;
long long f[4005][4005],a[4005],n,k,mina=INT_MAX,allow[4005],f2[4005],ju[4005];
vector<long long>v[4005];
void bfs(long long aaaa){
	memset(ju,0,sizeof ju);
	queue<long long>q;
	q.push(aaaa);
	ju[aaaa]=1;
	while(!q.empty()){
		long long r=q.front();q.pop();
		for(auto it:v[r]){
			if(ju[it]) continue;
			if(f2[it]){
				allow[it]=1;
				q.push(it);
				ju[it]=1;
			}
		}
	}
}
bool judge(){
	long long cnt=0;
	memset(allow,0,sizeof allow);
	for(long long i=1;i<=k;i++){
		if(!allow[a[i]]){
			bfs(a[i]);
			cnt++;
		}
	}
	return cnt<=2;
}
void dfs(long long x){
	if(x>k){
		memset(f2,0,sizeof f2);
		for(long long i=1;i<=k;i++) f2[a[i]]=1;
		if(!judge()) return ;
		long long maxi=0,d[4005];
		for(long long i=0;i<4005;i++) d[i]=INT_MAX;
		for(long long i=1;i<=n;i++){
			bool flag=0;
			for(long long j=1;j<=k;j++){
				if(a[j]==i){
					d[i]=0;
					flag=1;
					break;
				}
			}
			if(flag) continue;
			for(long long j=1;j<=k;j++){
				d[i]=min(d[i],f[i][a[j]]);
			}
		}
		for(long long i=1;i<=n;i++) maxi=max(maxi,d[i]);
		mina=min(mina,maxi); 
		return ;
	}
	for(long long i=a[x-1]+1;i<=n;i++){
		a[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	long long c,t;
	cin>>c>>t;
	while(t--){
		mina=INT_MAX;
		cin>>n>>k;
		for(long long i=0;i<4005;i++) for(long long j=0;j<4005;j++) f[i][j]=INT_MAX;
		for(long long i=1;i<n;i++){
			long long u,vv;
			cin>>u>>vv;
			v[u].push_back(vv);
			v[vv].push_back(u);
			f[u][vv]=1;
			f[vv][u]=1;
		}
		for(long long i=1;i<=n;i++) f[i][i]=0;
		for(long long k=1;k<=n;k++){
			for(long long i=1;i<=n;i++){
				for(long long j=1;j<=n;j++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		dfs(1);
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				cout<<f[i][j]<<' ';
			}
			cout<<'\n';
		}
		cout<<mina<<'\n'; 
	}
	return 0;
} 
