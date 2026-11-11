#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int x[2000005];
int dis[2000005],reach[2000005],cnt[2000005];
vector<int> a[2000005];
void dfs(int u,int step){
	bool f=0;
	for(int i:a[u]){
		if(!reach[i]) f=1;
	}
	if(f){
		for(int i:a[u]){
			step++;
			if(!reach[i]) reach[i]=1,dis[i]=step,dfs(i,step);
			else if(step==dis[i]) cnt[i]++;
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long ans=0;
		for(int i=1;i<=n;i++) {
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
					a[i].push_back(j);a[j].push_back(j);
				}
			}
		}
		for(int u=1;u<=n;u++) {
			memset(dis,0,sizeof(dis)/sizeof(int));
			memset(reach,0,sizeof(reach)/sizeof(int));
			memset(cnt,0,sizeof(cnt)/sizeof(int));
			dfs(u,0);
			for(int cntt:cnt){if(cntt==2)ans++;}
		}
		cout<<ans;
	}
	return 0;
}

