#include<bits/stdc++.h>
const int N=500;
const int M=5e5;
const int INF=1e10;
struct edge{
	int s;
	int v;
	bool operator<(edge a)const{
		return this->v<a.v;
	}
};
std::vector<edge> F[N+M+1];
std::vector<int> W(M+1,0);
std::vector<edge> TT[M+1];
int c,n,m,d,q;
int Dij(int start,int end){
    std::vector<int> V(m+1,INF); 
	std::priority_queue<edge> PQ;
	V[start]=0;
	PQ.push({start,0});
	for(int i=0;i<TT[start].size();i++){
		PQ.push({TT[start][i]});
	}
	while(!PQ.empty()){
		edge v=PQ.top();
		PQ.pop();
		if(V[v.s]!=v.v)continue;
		for(int j=0;j<F[v.s].size();j++){
			edge i=F[v.s][j];
			PQ.push(i);
			V[i.s]=std::min(V[i.s],v.v+i.v);
		}
	}
	return V[end];
}
int main(){
	std::freopen("subway.in","r",stdin);
	std::freopen("subway.out","w",stdout);
	std::cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
		std::cin>>W[i];
	for(int i=0;i<n;i++){
		int k;
		std::cin>>k;
		int a,t;
		for(int j=0;j<k;j++){
			std::cin>>a>>t;
			TT[j].push_back({i,t});
			F[i].push_back({a+n,W[a]+t});
			F[a+n].push_back({i,W[a]+t});
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<TT[i].size();j++){
			for(int k=j+1;k<TT[i].size();k++){
			    F[n+j].push_back({n+k,TT[i][j].v+TT[i][k].v}); 
			    F[n+k].push_back({n+j,TT[i][j].v+TT[i][k].v}); 
		    }
		}
	}
	for(int i=0;i<q;i++){
		int s,e;
		std::cout<<Dij(s-1,e-1)<<"\n";
	}
}
