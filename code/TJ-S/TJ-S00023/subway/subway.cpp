#include <iostream>
#include <vector>
#include <queue>
struct po{
	int a,t;
};
struct pt{
	bool status;
	int pos,cost;
	bool operator<(const pt& o)const{
		return cost < o.cost;
	}
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int c,n,m,d,q;
	std::cin >> c >> n >> m >> d >> q;
	std::vector<int> w(m);  //least
	std::vector<std::vector<po>>p(n);
	std::vector<std::vector<int>>u(m);
	for(int i=0;i<n;i++){
		int l;
		std::cin >> l;
		p[i].resize(l);
		for(int k=0;k<p[i].size();k++){
			std::cin >> p[i][k].a >> p[i][k].t;
			u[p[i][k].a].push_back(i);
		}

	}
	for(int i=1;i<=q;i++){
		std::priority_queue<pt>pq;
		int x,y;
		std::cin >> x >> y;
		int cost;
		cost += w[x]+w[y];
		pq.push({1,x,0});
		while(pq.top().pos!=y){
			pt now = pq.top();
			pq.pop();
			if(now.status){
				for(int i=0;i<u[now.pos].size();i++)
					pq.push({0,u[now.pos][i],now.cost+p[u[now.pos][i]][now.pos].t});
			}
			else{
				for(int i=0;i<p[now.pos].size();i++)
					pq.push({1,p[now.pos][i].a,now.cost});
			}
		}
		std::cout << cost+pq.top().cost << "\n";
	}
	std::cout << std::endl;
}
