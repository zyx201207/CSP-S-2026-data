#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2001021],num[2001021],ans;
vector<long long>g[2001021];
long long dfs(long long u,long long v){
	long long cnt=2000000000000000100;
	if(x[v]-x[u]<=d){
		num[u]=1;
		return 1;
	}
	else{
		for(long long i=g[u].size()-1;i>=0;i--){
			if(num[g[u][i]]!=0){
				continue;
			}
			long long save=dfs(g[u][i],v);
			if(save<cnt){
				cnt=save;
				num[u]=num[g[u][i]];
			}
			else if(save==cnt){
				num[u]+=num[g[u][i]];
			}
		}
	}
	return cnt+1;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(long long k=1;k<=t;k++){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		for(long long i=1;i<n;i++){
			c=i;
			while(c<=n&&x[c+1]-x[i]<=d){
				c++;
				g[i].push_back(c);
			}
		}
		for(long long i=1;i<=n-3;i++){
			for(long long j=i+3;j<=n;j++){
				c=dfs(i,j);
				if(num[i]==2){
					ans+=1;
				}
				memset(num,0,sizeof(num));
			}
		}
		cout<<ans<<endl;
		ans=0;
		for(long long i=1;i<=n;i++){
			while(!g[i].empty()){
				g[i].pop_back();
			}
		}
	}
	return 0;
}