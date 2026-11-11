#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000010],dis[5005][5005],vis[5005][5005],ans,flag=1,sum;
vector<long long> e[5005];
void dfs(long long st,long long u,long long f,long long dd){
	if(dd<dis[st][u]){
		dis[st][u]=dd;
		vis[st][u]=1;
	}
	else if(dd==dis[st][u]){
		vis[st][u]++;
	}
	for(long long v:e[u]){
		if(v==f) continue;
		dfs(st,v,u,dd+1);
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<=1){
			cout<<"0\n";
			continue;
		}
		if(n<=5000){
			ans=0;
			memset(dis,0x3f3f3f3f3f3f3f3f,sizeof dis);
			memset(vis,0,sizeof vis);
			for(long long i=1;i<=n;i++) e[i].clear();
			for(long long i=1;i<=n;i++){
				for(long long j=i+1;j<=n;j++){
					if(x[j]-x[i]<=d){
						e[i].push_back(j);
						e[j].push_back(j);
					}
				}
			}
			for(long long i=1;i<=n;i++) dfs(i,i,0,0);
			for(long long i=1;i<=n;i++){
				for(long long j=i+1;j<=n;j++){
					if(vis[i][j]==2){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		flag=1;
		sum=x[2]-x[1];
		for(long long i=2;i<=n-1;i++){
			if(x[i+1]-x[i]!=sum){
				flag=0;
				break;
			}
		}
		if(flag){
			sum=d/sum;
			if(sum<=1) sum=0;
			else{
				sum=sum*2-1;
				if(sum>n) sum=0;
				else sum=n-sum;
			}
			cout<<sum<<"\n";
		}
		else{
			cout<<"0\n";
		}
	}
	return 0;
}