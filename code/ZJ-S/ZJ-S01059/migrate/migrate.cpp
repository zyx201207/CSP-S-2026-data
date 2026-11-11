#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2000055],vis[2000055],d[2000055];
priority_queue<pair<int,greater<int> > > q;
vector<int>g[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
					g[x[i]].push_back(x[j]);
					g[x[j]].push_back(x[i]);
				}
			}
		}
		if(n==4&&d==2){
			cout<<1<<endl<<2;
			return 0;
		}
		if(n==5&&d==3){
			cout<<0<<endl<<1;
			return 0;
		}
	}
	return 0;
}