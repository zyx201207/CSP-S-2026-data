#include<bits/stdc++.h>
using namespace std;
//bool _st;
const int M=20100;
long long n,m,c,d,q,x,y,aa;
long long ans;
long long w[M],k[600];
long long tt;
long long ff[600][M+500],fy[3][500010];
vector<pair<long long,int>> ve[M+600];
priority_queue<pair<long long,int>,vector<pair<long long ,int>> ,greater<pair<long long,int>>> qq;
//bool _ed;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	cerr<<abs(&_st-&_ed)/1024.0/1024<<" MB\n";
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];//i号地铁站的地铁口到站厅所需时间 
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];//i条地铁线经过的地铁站数
		for(int j=1;j<=k[i];j++){
			cin>>aa;//第i条线路的第j个地铁站aa
			cin>>tt;//第i条线的站台走到aa地铁站的站厅所需时间 
			ve[aa].push_back({tt,i+m});
			ve[m+i].push_back({tt,aa});
		} 
	}
	if(n<=2 && m>=M){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m+n;j++){
				fy[i][j]=1e18;
			}
			fy[i][i+m]=0;
			qq.push({0,i+m});
			while(!qq.empty()){
				int id=qq.top().second;
				long long fs=qq.top().first;
				qq.pop();
				if(fs!=fy[i][id]){
					continue;
				}
				for(auto it:ve[id]){
					if(fy[i][it.second]>fy[i][id]+it.first){
						fy[i][it.second]=fy[i][id]+it.first;
						qq.push({fy[i][it.second],it.second});
					}
				}
			}
		}
	
		for(int i=1;i<=q;i++){
			ans=1e18;
			cin>>x>>y;
			for(auto it:ve[x]){
				ans=min(ans,fy[it.second-m][x]+fy[it.second-m][y]);
			}
			cout<<w[x]+w[y]+ans<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m+n;j++){
			ff[i][j]=1e18;
		}
		ff[i][i+m]=0;
		qq.push({0,i+m});
		while(!qq.empty()){
			int id=qq.top().second;
			long long fs=qq.top().first;
			qq.pop();
			if(fs!=ff[i][id]){
				continue;
			}
			for(auto it:ve[id]){
				if(ff[i][it.second]>ff[i][id]+it.first){
					ff[i][it.second]=ff[i][id]+it.first;
					qq.push({ff[i][it.second],it.second});
				}
			}
		}
	}

	for(int i=1;i<=q;i++){
		ans=1e18;
		cin>>x>>y;
		for(auto it:ve[x]){
			ans=min(ans,ff[it.second-m][x]+ff[it.second-m][y]);
		}
		cout<<w[x]+w[y]+ans<<"\n";
	}
	return 0;
}
//n 地铁线路数 500
//m 地铁站数 5e5
//d 每个地铁最多被几条线路经过 20
//q 出行计划数  1e5
//w 1e9
//t 1e9

