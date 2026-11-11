#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,t;
int a[N];
bool vis[N];
int sum[N];
int dist[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		int ans=0;
		//memset(vis,0,sizeof(vis));
		int n,d;
		cin>>n>>d;
		
	//	memset(sum,0,sizeof(sum));
	//	int mx=-1e18,mn=1e18;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		//	mx=max(mx,a[i]);
			//mn=min(mn,a[i]);
		}
	//	sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			memset(sum,0,sizeof(sum));
		//	if(vis[i]) continue;
			priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
			memset(dist,0x3f,sizeof(dist));
			dist[i]=0;
			pq.push({0,i});
			while(!pq.empty()){
				auto [j,k]=pq.top();
				pq.pop();
				if(vis[k]){
					continue;
				}
				vis[k]=1;
				if(j>dist[k]) continue;
				int jkl=k+1;
				while(jkl<=n&&a[jkl]-a[k]<=d){
					if(dist[jkl]==j+1){
						sum[jkl]++;
					}else{
						if(dist[jkl]>j+1){
							sum[jkl]=1;
							dist[jkl]=j+1;
							pq.push({j+1,jkl});
						}
					}
					jkl++;
				}
				jkl=k-1;
				while(jkl>=1&&abs(a[jkl]-a[k])<=d){
					if(dist[jkl]==j+1){
						sum[jkl]++;
					}else{
						if(dist[jkl]>j+1){
							sum[jkl]=1;
							dist[jkl]=j+1;
							pq.push({j+1,jkl});
						}
					}
					jkl--;
				}
			}
			for(int lj=1;lj<=n;lj++){
				if(lj==i) continue;
				if(sum[lj]==2){
			//		cout<<i<<" "<<lj<<"\n";
					ans++;
				}
			}
		}
		cout<<ans/2<<"\n";
	}
	return 0;
}//j:[80,100]+100+[50,80]+[4,28]=[234,308]
//AFO
//CSP-2026=NOIP-2025
