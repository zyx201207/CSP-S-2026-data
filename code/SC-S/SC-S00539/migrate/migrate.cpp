#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int x[2000001];
int minw;
int num=0;
vector<int> v[200001];
bool vis[200001];
void dfs(int p,int w,int ed){
	if(p==ed){
		if(w<minw){
			minw=w;
			num=1;
		}
		else if(w==minw){
			num++;
		}
		return;
	}
	for(int i:v[p]){
		if(vis[i]==1)continue;
		vis[i]=1;
		dfs(i,w+1,ed);
		vis[i]=0;
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(n>=100){
			if((d/(x[2]-x[1]))<=1){
				cout<<0<<"\n";
				continue;
			}
			if((d/(x[2]-x[1]))>=n){
				cout<<0<<"\n";
				continue;
			}
			cout<<n-2*d/(x[2]-x[1])+1<<"\n";
			continue;
		}
		for(int i=1;i<n;i++){
			v[i].clear();
			for(int j=i+1;j<=n;j++){
				if(abs(x[j]-x[i])<=d){
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				minw=0x3f3f3f3f;
				num=0;
				memset(vis,0,sizeof vis);
				dfs(i,0,j);
				if(num==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}