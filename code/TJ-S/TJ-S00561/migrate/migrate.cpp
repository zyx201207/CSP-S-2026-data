#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long pty[5005];
long long dist[5005][5005];
long long distn[5005][5005];
void dfs(long long k,long long u,long long cnt,long long m,long long n){
	if(u>n) return;
	if(dist[k][u]==cnt&&k!=u) distn[k][u]++;
	if(cnt>dist[k][u]&&k!=u) return;
	for(long long i=u+1;i<=n;i++){
		if(pty[i]-pty[u]>m) break;
//		cout<<k<<" "<<i<<" "<<cnt+1<<'\n';
		dfs(k,i,cnt+1,m,n);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		long long n,m;
		cin>>n>>m;
		for(long long i=1;i<=n;i++){
			cin>>pty[i];
			for(long long j=1;j<=n;j++){
				dist[i][j]=dist[j][i]=distn[i][j]=distn[j][i]=0;
			}
		}
		for(int i=1;i<=n;i++){
			long long kn=i;
			long long piuh=1;
			for(long long j=i+1;j<=n;j++){
				if(pty[j]-pty[kn]<=m){
					dist[kn][j]=dist[j][kn]=1;
					dist[i][j]=dist[j][i]=piuh;
				}else{
					if(kn==j-1) break;
					kn=j-1;
					j--;
					piuh++;
				}
			}
			dfs(i,i,0,m,n);
		}
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(distn[i][j]==2)ans+=1;
//				cout<<distn[i][j]<<" ";
			}
//			cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
