#include<bits/stdc++.h>
#define int long long
#define pii pair<long,long>
using namespace std;
const int N=5e5+509;
int w[N];
vector<pair<int,int> > a[N];
priority_queue<pii,vector<pii>,greater<pii> > q; 
bool vis[N];
int c,n,NN,m,d,qq;
namespace lzy{
	const int M=5e4+509; 
	long long f[505][M];
	void dij(int s,int k){
		f[k][s]=0;
		while(q.size()) q.pop();
		memset(vis,0,sizeof(vis));
		q.push({0,s});
		while(q.size()){
			pii t=q.top();q.pop();
			if(vis[t.second]!=0){
				continue;
			}
			vis[t.second]=1;
			for(auto v:a[t.second]){
				if(t.first+v.second<f[k][v.first]){
					f[k][v.first]=t.first+v.second;
					q.push({f[k][v.first],v.first});
				}
			}
		}
	}
	void Main(){
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=NN;i++){
			dij(n+i,i);
		}
		int x,y;
		while(qq--){
			cin>>x>>y;
			long long ans=f[1][x]+f[1][y];
			for(int i=2;i<=NN;i++){
				long long p=f[i][x]+f[i][y];
				ans=min(ans,p);
			}
			cout<<w[x]+w[y]+ans<<"\n";
		} 
		return;
	}
}

namespace lz{
	const int M=5e5+509; 
	long long f[50][M];
	void dij(int s,int k){
		f[k][s]=0;
		while(q.size()) q.pop();
		memset(vis,0,sizeof(vis));
		q.push({0,s});
		while(q.size()){
			pii t=q.top();q.pop();
			if(vis[t.second]!=0){
				continue;
			}
			vis[t.second]=1;
			for(auto v:a[t.second]){
				if(t.first+v.second<f[k][v.first]){
					f[k][v.first]=t.first+v.second;
					q.push({f[k][v.first],v.first});
				}
			}
		}
	}
	void Main(){
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=NN;i++){
			dij(n+i,i);
		}
		int x,y;
		while(qq--){
			cin>>x>>y;
			long long ans=f[1][x]+f[1][y];
			for(int i=2;i<=NN;i++){
				long long p=f[i][x]+f[i][y];
				ans=min(ans,p);
			}
			cout<<w[x]+w[y]+ans<<"\n";
		} 
		return;
	}
}

namespace yj{
	const int M=5e5+509; 
	long long f[M];
	void dij(int s){
		memset(f,0x3f,sizeof(f));
		f[s]=0;
		while(q.size()) q.pop();
		memset(vis,0,sizeof(vis));
		q.push({0,s});
		while(q.size()){
			pii t=q.top();q.pop();
			if(vis[t.second]!=0){
				continue;
			}
			vis[t.second]=1;
			for(auto v:a[t.second]){
				if(t.first+v.second<f[v.first]){
					f[v.first]=t.first+v.second;
					q.push({f[v.first],v.first});
				}
			}
		}
	}
	void Main(){
		int x,y;
		while(qq--){
			cin>>x>>y;
			dij(x);
			long long ans=f[y];
			cout<<w[x]+w[y]+ans<<"\n";
		} 
		return;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>NN>>m>>d>>qq;
	n=m;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	int v,t,k;
	int sum=0;
	for(int i=1;i<=NN;i++){
		cin>>k;
		sum+=k;
		for(int j=1;j<=k;j++){
			cin>>v>>t;
			a[n+i].push_back({v,t});
			a[v].push_back({n+i,t});
		}
	}
	if(sum<=5e4){
		lzy::Main();
	}
	else if(n<=50){
		lz::Main();
	}
	else{
		yj::Main();
	}
	return 0;
}
