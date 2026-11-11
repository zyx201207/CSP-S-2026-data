#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=2e6+18e5+5;
int c,n,m,d,q;
vector<PII>edge[N];
int a[500005],t[500005];
long long dis[N];
bool flag[N];
void Dijkstra(int start){
	memset(dis,0x3f,sizeof dis);
	memset(flag,0,sizeof flag); 
	dis[start]=0;
	priority_queue<PII,vector<PII>,greater<PII> >q;
	q.push({0,start});
	while(!q.empty()){
		PII t=q.top();
		q.pop();
		if(flag[t.second])continue;
		flag[t.second]=1;
		for(auto i:edge[t.second]){
			if(t.first+i.second<dis[i.first]){
				dis[i.first]=t.first+i.second;
				q.push({dis[i.first],i.first});
			}
		}
	}
}
int main(){
	//2*m+x µØÌú¿Ú
	//m+x Õ¾Ìü 
	// x Õ¾Ì¨ 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		edge[2*m+i].push_back({m+i,x});
		edge[m+i].push_back({2*m+i,x});
//		cout<<2*m+i<<"<------->"<<m+i<<"???\n";
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			if(i==1){
				edge[m+a[j]].push_back({a[j],t[j]});
				edge[a[j]].push_back({m+a[j],t[j]});
			}else{//cout<<a[j]+(k+1)*m<<"????\n";
				edge[m+a[j]].push_back({a[j]+(i+1)*m,t[j]});
				edge[a[j]+(i+1)*m].push_back({m+a[j],t[j]});
				edge[a[j]+(i+1)*m].push_back({a[j],0});
				edge[a[j]].push_back({a[j]+(i+1)*m,0});
			}
			
		//	cout<<m+a[j]<<"<------>"<<a[j]<<"!!\n";
		}
		for(int j=2;j<=k;j++){
			edge[a[j]+(i+1)*m].push_back({a[j-1]+(i+1)*m,0});
			edge[a[j-1]+(i+1)*m].push_back({a[j]+(i+1)*m,0});
//			cout<<a[j]<<"<-----/*->"*/<<a[j-1]<<"+++\n";
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		Dijkstra(m*2+u);
		cout<<dis[m*2+v]<<endl;
	}
	return 0;
}
