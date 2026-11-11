#include<bits/stdc++.h>
using namespace std;

const int M = 5e5+4;

struct edge{
	int t;
	int nx;
	edge(){
		t = 0,nx = -1;
	}
	edge(int t1,int nx1){
		t = t1,nx = nx1;
	}
};

struct ques{
	int be,en;
	long long ans;
};

vector<edge> p[M];
int n,m,d,q,w[M];
ques qu[100004];

void iline(){
	vector<int> a,t;
	int k;
	scanf("%d",&k);
	for(int i = 1;i <= k;i++){
		int a1,t1;
		scanf("%d%d",&a1,&t1);
		a.push_back(a1);
		t.push_back(t1);
	}
	for(int i = 0;i < k;i++){
		for(int j = 0;j < k;j++){
			if(i != j){
				bool flag = 1;
				for(int k = 0;k < p[i].size();k++){
					if(p[i][k].nx == a[j]){
						flag = 0;
						p[i][k].t = min(p[i][k].t,t[i]+t[j]);
					}
				}
				if(flag){
					p[a[i]].push_back(edge{t[i]+t[j],a[j]});
				}
			}
		}
	}
}

/*bool cmp(const ques& a,const ques& b){
	return a.be < b.be;
}*/

void init(){
	scanf("%d%d%d%d",&n,&m,&d,&q);
	for(int i = 1;i <= m;i++){
		scanf("%d",&w[i]);
	}
	for(int i = 1;i <= n;i++){
		iline();
	}
	for(int i = 1;i <= q;i++){
		scanf("%d%d",&qu[i].be,&qu[i].en);
	}
	//sort(qu+1,qu+q+1,cmp);
	/*for(int i = 1;i <= m;i++){
		cout << i << " : ";
		for(int j = 0;j < p[i].size();j++){
			cout << p[i][j].t << " " << p[i][j].nx << " , ";
		}
		cout << endl;
	}*/
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

long long tp[M];

void dfs(int thp,long long co){
	tp[thp] = co;
	for(int i = 0;i < p[thp].size();i++){
		int nxp = p[thp][i].nx,co1 = p[thp][i].t;
		if(tp[nxp] == -1 || tp[nxp] > co+co1){
			dfs(nxp,co+co1);
		}
	}
}

void work(){
	int be = -1;
	for(int i = 1;i <= q;i++){
		if(be != qu[i].be){
			for(int l = 0;l <= m+1;l++){
				tp[l] = -1;
			}
			be = qu[i].be;
			dfs(be,0);
		}
		qu[i].ans = tp[qu[i].en]+w[be]+w[qu[i].en];
	}
	for(int i = 1;i <= q;i++){
		printf("%lld\n",qu[i].ans);
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	scanf("%d",&c);
	init();
	work();
	return 0;
}
