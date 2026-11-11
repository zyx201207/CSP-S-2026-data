#include<bits/stdc++.h>
#define pii pair<long long,long long>
using namespace std;

int c,n,m,d,Q;
struct node{
	long long w;
	long long k;
	vector<pii> e;
	vector<pii> ne;
}v[500005];

long long road[500005][2];
void read(){
	cin >> c >> n >> m >> d >> Q;
	for(int i=1;i<=m;++i) cin >> v[i].w;
	for(int i=1;i<=n;++i){
		cin >> road[0][0];//cout << i << ": " << road[0][0] << "\n";
		for(int j=1;j<=road[0][0];++j){
			cin >> road[j][0] >> road[j][1];
			//cout << "	" << j << "\n";
		} 
		for(int j=1;j<road[0][0];++j)
		for(int k=j+1;k<=road[0][0];++k){
			v[road[j][0]].e.push_back({road[k][0],road[j][1]+road[k][1]});
			v[road[k][0]].e.push_back({road[j][0],road[j][1]+road[k][1]});
		}
	}
	for(int i=1;i<=m;++i){
		sort(v[i].e.begin(),v[i].e.end());
		int id=0;
		for(int j=0;j<v[i].e.size();){
			if(v[i].e[j].first != id){
				id=v[i].e[j].first;
				v[i].ne.push_back({v[i].e[j].second,id});
			}else{
				while(v[i].e[j].first == id)j++;
			}
		}
		sort(v[i].ne.begin(),v[i].ne.end());
	}
}

long long times[505][505];
bool vis[505];
queue<pii> q;
void work_times(){
	
	for(int i=1;i<=m;++i) times[i][i]=0;
	
	for(int i=1;i<=m;++i){
//		cout << i << ":" << "\n";
		for(int j=1;j<=m;++j){
			vis[j]=0;
		}
		q.push({0,i});
		while(q.size()){
			pii root=q.front();q.pop();
			long long cost=root.first,ui=root.second;
			if(vis[ui] == 1)continue;
			vis[ui]=1;//			cout << "	" << ui << ": " << cost << "\n";
			for(auto j:v[ui].ne){
				long long wi=j.first,vi=j.second;
				times[i][vi]=min(cost+wi,(times[i][vi] != 0 ? times[i][vi]:wi+cost));
				times[vi][i]=min(cost+wi,(times[vi][i] != 0 ? times[vi][i]:wi+cost));
//				 		cout << "		" << "t[" << i << "][" << vi << "]= " << times[i][vi] << "\n";
				if(vis[vi] == 0){
					q.push({times[i][vi],vi});
				}
			}
		}
	}
	
}

void write(){
	while(Q--){
		int ui,vi;
		cin >> ui >> vi;
		cout << times[ui][vi]+v[ui].w+v[vi].w << "\n";
	}
}

void DeBug(){
	for(int i=1;i<=m;++i){
//		for(auto j:v[i].ne){
//			cout << " [" << j.second << "]: " << j.first << "  ";
//		}
//		cout << "\n";
//		for(int j=1;j<=m;++j){
//			cout << times[i][j] << " ";
//		}
//		cout << "\n";
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(0),cin.tie(0);
	
	read();
	work_times();
	write();
	
	DeBug();
	
	return 0;
}