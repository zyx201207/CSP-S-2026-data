#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node{
	int idx,dis;
	bool operator < (const Node a) const{
		if (dis>a.dis) return true;
		else return false;
	}
};

struct Edge{
	int v,w;
};

priority_queue<Node> q;
vector<Edge> e[5000005];

int c,n,m,d,Q,bianhao;

int W[500005],K[505],DIS[5000005],f[5000005],daan[2005][2005];

void fnd(int A,int B,int C){
	Edge e1 ;
	e1.v = A;
	e1.w = C;
	Edge e2;
	e2.v = B;
	e2.w = C;
	
	e[B].push_back(e1);
	e[A].push_back(e2);
}

void dij(int stt,int edd){
	for (int i = 1;i<=bianhao;i++){
		DIS[i] = 1e18;
		f[i] = 0;
	}
	Node s;
	s.idx = stt;s.dis = 0;DIS[stt] = 0;
	q.push(s);
	
	while (!q.empty()){
		Node u = q.top();
		q.pop();
		
		if(f[u.idx])continue;
		f[u.idx] = 1;
		
		for (int i = 0 ;i<e[u.idx].size();i++){
			Edge t = e[u.idx][i];
			if (DIS[t.v]>DIS[u.idx]+t.w) {
				q.push({t.v,DIS[u.idx]+t.w});
				DIS[t.v] = DIS[u.idx]+t.w;
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>Q;
	
	for (int i = 1;i<=m;i++) {
		scanf("%lld",&W[i]);
		fnd(i,i+m,W[i]);
	}
	bianhao = 2*m;
	for (int i = 1;i<=n;i++){
		scanf("%lld",&K[i]);
		for (int j = 1;j<=K[i];j++){
			bianhao ++;
			int ditiezhan,shijian;
			
			scanf("%lld",&ditiezhan);
			scanf("%lld",&shijian);
			
			fnd(bianhao,ditiezhan+m,shijian);
			if (j>1)fnd(bianhao,bianhao-1,0);
		}
	}
	if (Q<m || m>2000){
		for (int i = 1;i<=Q;i++){
			int qidian,zhongdian;
			
			scanf("%lld",&qidian);
			scanf("%lld",&zhongdian);
			
			dij(qidian,zhongdian);
			
			printf("%lld\n",DIS[zhongdian]);
		}
		return 0;	
	}
	
	else {
		for (int i = 1;i<=m;i++){
			dij(i,i);
			for (int j = 1;j<=m;j++){
				daan[i][j] = DIS[j];
			}
		}
		for (int i = 1;i<=Q;i++){
			int qidian,zhongdian;
			
			scanf("%lld",&qidian);
			scanf("%lld",&zhongdian);
			
			
			printf("%lld\n",daan[qidian][zhongdian]);
		}
		return 0;	
	}
	
}
