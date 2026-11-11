#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans=0,a[2000005],b[2000005],jbda=0,m;
vector<pair<int,int> >ve[200005];
void dfs(int now,int zhongdian,int cnt){
	if(now==zhongdian){
		if(ans==cnt){
			jbda++;
		}
		else if(ans>cnt){
			ans=max(ans,cnt);
			jbda=1;
		}
		return;
	}
	b[now]=1;
	for(auto p:ve[now]){
		int u=p.first;
		if(b[u]==0&&p.second<=m){
			dfs(u,zhongdian,cnt+1);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,daan=0;
	cin>>c>>t;
	while(t--){
		int n;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i!=1){
				ve[a[i]].push_back({a[i+1],a[i+1]-a[i]});
				ve[a[i+1]].push_back({a[i],a[i+1]-a[i]});
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				dfs(i,j,0);
				if(jbda==2){
					daan++;
					ans=-1;
					jbda=0;
				}
			}
		}
		cout<<daan<<endl;
	}
	return 0;
}
