
#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define PII pair<int,int>
long long c,n,m,d,qe,y,T;
int dist2[2000005],dist[2000005],dist3[2000005],x[2000005],vis[2000005];
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
vector <int> v[2000005];

void mem(){
	memset(dist,0x3f,sizeof(dist));
	memset(dist2,0x3f,sizeof(dist2));
	memset(dist3,0x3f,sizeof(dist3));
	memset(vis,0,sizeof(vis));
	while(q.size()) q.pop();
} 
void dij(int u){
	q.push({0,u});
	dist[u]=0;
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto c:v[u]){
			if(dist[c]>=dist[u]+1){
				dist3[c]=dist2[c];
				dist2[c]=dist[c];
				dist[c]=dist[u]+1;
				q.push({dist[c],c});
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//int n,m;
	cin>>c>>T;
	while(T--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(abs(x[i]-x[j])<=d){
					v[i].push_back(j);
					v[j].push_back(i);
				}else{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++){
			mem();
			dij(i);
			for(int j=i+3;j<=n;j++){
			//	cout<<dist3[j];
				//cout<<i<<" "<<j<<" "<<dist[j]<<" "<<dist2[j]<<" "<<dist3[j]<<"\n"; 
				if(dist2[j]==dist[j]&&dist2[j]!=dist3[j]&&j>=i+4){
				//	cout<<i<<" "<<j<<" "<<dist[j]<<"\n"; 
					ans++;
				}else if(dist2[j]==dist[j]){
				//	cout<<i<<" "<<j<<" "<<dist[j]<<"\n"; 
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
} 

