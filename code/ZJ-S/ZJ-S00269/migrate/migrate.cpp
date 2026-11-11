#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,INF=1e15;
int C,t,n,d,x[N];
void case10(){
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==1){
			cout<<"0\n";
			continue;
		}
		vector<int>G[n+3];
		for(int i=1;i<n;i++){
			for(int j=i;j<=n;j++){
				if(x[j]-x[i]<=d){
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}
		vector<vector<int>>dis(n+3,vector<int>(n+3,INF));
		vector<vector<short>>f(n+3,vector<short>(n+3,0));
		for(int i=1;i<=n;i++){
			queue<int>q;
			q.push(i);
			vector<bool>vis(n+3,false);
			dis[i][i]=0;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				if(vis[u]){
					continue;
				}
				vis[u]=true;
				for(auto&v:G[u]){
					if(dis[i][u]+1<dis[i][v]){
						dis[i][v]=dis[i][u]+1;
						q.push(v);
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			queue<int>q;
			q.push(i);
			vector<bool>vis(n+3,false);
			f[i][i]=1;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				if(vis[u]){
					continue;
				}
				vis[u]=true;
				for(auto&v:G[u]){
					if(dis[i][u]+1==dis[i][v]){
						f[i][v]+=f[i][u];
						if(f[i][v]<=2){
							q.push(v);
						}
						else{
							f[i][v]=3;
						}
					}
				}
			}
			for(int j=1;j<=n;j++){
				if(f[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans/2<<'\n';
	}
}
void case12(){
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==1){
			cout<<"0\n";
			continue;
		}
		int fw=d/(x[2]-x[1]);
		cout<<(fw<=1||(n+1)/2<fw?0:n-fw*2+1)<<'\n';
	}
}
void case14(){
	while(t--){
		int k,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int l,r;
		for(int i=n;i>=1;i--){
			if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
				r=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
				l=i;
				break;
			}
		}
		if(r>l){
			cout<<"0\n";
			continue;
		}
		k=l;
		for(int i=1;i<l;i++){
			int it=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
			if(it==k){
				it--;
			}
			int itt=upper_bound(x+1,x+1+n,x[it]+d)-x-1;
			if(itt>=n){
				continue;
			}
			ans+=n-itt;
		}
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>t;
	if(C<=10){
		case10();
		return 0;
	}
	if(C<=12){
		case12();
		return 0;
	}
	if(C<=14){
		case14();
		return 0;
	}
	return 0;
}
