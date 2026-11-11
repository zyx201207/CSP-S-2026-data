#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int x,y;
long long c,n,m,d,q;
vector<long long> e[N];
long long a[N],t[505][505],p[N];
bool vis[N];
int shn[N];
long long dist[N];
vector<long long>ls;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//insert erase top empty pop priority_queue<<int>,vector<int>,greater<int> >
	//begin end find
	//无向图
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;++i){
		cin>>a[i];
	}
	for(int i=0;i<n;++i){
		int k;
		cin>>k;
		cin>>p[0]>>t[0][p[0]];
		for(int j=1;j<k;++j){
			cin>>p[j];
			shn[p[j]]++;
			cin>>t[p[j-1]][p[j]];
		}
		for(int j=1;j<k;++j){
			e[p[j-1]].push_back(p[j]);
			e[p[j]].push_back(p[j-1]);
		}
	}
	for(int i=0;i<n;++i){
		sort(e[i].begin(),e[i].end());
	}
	for(int i=0;i<q;++i){
		cin>>x>>y;
		queue<long long>q;
		memset(vis,0,sizeof(vis));
		//0 2 5 20 1 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3
		memset(dist,-1,sizeof(dist));
		dist[x]=a[x];
		q.push(x);
		vis[x]=1;
		int last=x;
		while(!q.empty()){
			int m=q.front();
			q.pop();
			dist[m]=t[last][m];
			last=m; 
			if(m==y){
				break;
			}
			for(auto o:e[m]){
				if(vis[o]!=1){
					q.push(o);
					dist[o]=dist[m]+t[m][o];
					if(shn[o]>=2){
						dist[o]+=a[m];
					}
				}
				vis[o]=1;
			}
			
		}
		dist[y]+=a[y];
		cout<<dist[y]<<endl;
	}
	return 0;
}
