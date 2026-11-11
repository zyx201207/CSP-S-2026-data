#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int arr[N];
vector<int> cg[510];
vector<pair<int,long long> > g[N];
int vis[N];
vector<int> zhan[N];
long long ans=1e18;
void dfs(int x,int zhong,long long timee){
	vis[x]=1;
	if(x==zhong){
		ans=min(ans,timee);
	}
	for(int i=0;i<g[x].size();i++){
		int tx=g[x][i].first;
		if(!vis[tx]) dfs(tx,zhong,timee+g[x][i].second);
	}
}
void dfsc(int x,long long timee,int zhong,long long quan){
	for(int i=0;i<cg[zhong].size();i++){
		if(cg[zhong][i]==x){
			ans=min(ans,timee+arr[zhong]);
			return;
		}
	}
	for(int i=0;i<cg[x].size();i++){
		int tx=cg[x][i];
		if(!vis[tx]) dfs(tx,timee+quan,zhong);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c;
	if(c==7||c==8||c==9||c==10||c==11){
		int n,m,d,q;
		cin>>n>>m>>d>>q;
		for(int i=1;i<=m;i++){
			scanf("%d",&arr[i]);
		}
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			int lst=0;
			long long lstt=0;
			for(int j=1;j<=k;j++){
				int a;
				long long t;
				scanf("%d %lld",&a,&t);
				if(j==1){
					lst=a;
					lstt=t;
				}else{
					g[lst].push_back({a,lstt+t});
					g[a].push_back({lst,lstt+t});
					lst=a;
					lstt=t;
				}
			}
		}
		while(q--){
			for(int i=1;i<=1000;i++){
				vis[i]=0;
			}
			int shi,zhong;
			scanf("%d %d",&shi,&zhong);
			ans=1e18;
			dfs(shi,zhong,arr[shi]);
			printf("%lld\n",ans+arr[zhong]);
		}
	}else if(c>=12&&c<=19){
		int n,m,d,q;
		cin>>n>>m>>d>>q;
		int quan=0;
		for(int i=1;i<=m;i++){
			scanf("%d",&arr[i]);
		}
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int a,t;
				cin>>a>>t;
				quan=t;
				zhan[a].push_back(i);
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=0;j<zhan[i].size();j++){
				for(int k=0;k<zhan[i].size();k++){
					if(j==k) continue;
					cg[zhan[i][j]].push_back(zhan[i][k]);
				}
			}
		}
		while(q--){
			int shi,zhong;
			scanf("%d %d",&shi,&zhong);
			ans=1e18;
			for(int i=0;i<cg[shi].size();i++){
				int tx=cg[shi][i];
				dfsc(tx,0,zhong,quan);
			}
		}
	}else{
		int n,m,d,q;
		cin>>n>>m>>d>>q;
		for(int i=1;i<=m;i++){
			scanf("%d",&arr[i]);
		}
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			int lst=0;
			long long lstt=0;
			for(int j=1;j<=k;j++){
				int a;
				long long t;
				scanf("%d %lld",&a,&t);
				if(j==1){
					lst=a;
					lstt=t;
				}else{
					g[lst].push_back({a,lstt+t});
					g[a].push_back({lst,lstt+t});
					lst=a;
					lstt=t;
				}
			}
		}
		while(q--){
			int shi,zhong;
			scanf("%d %d",&shi,&zhong);
			ans=1e18;
			for(int i=0;i<g[shi].size();i++){
				if(g[shi][i].first==zhong){
					ans=min(ans,arr[shi]+arr[zhong]+g[shi][i].second);
				}
			}
			if(ans==1e18) printf("77\n");
			printf("%lld\n",ans);
			
		}
	}
	return 0;
}
