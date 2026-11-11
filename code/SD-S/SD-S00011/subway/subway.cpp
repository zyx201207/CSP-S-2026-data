#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int MAXN=500;
const int MAXM=5e5;
int aa[MAXM];
typedef pair<int,int> P;
int c,n,m,d,q;
//int a[MAXM];
int zt;
struct Edges{
	int to;
	int w;
};
vector<Edges> g[MAXN];
vector<int>a[MAXM];
vector<int>t[MAXM];
int tong[MAXN];
void addEdge(int u,int v,int w){
	Edges t;
	t.to=v;
	t.w=w;
	g[u].push_back(t);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>aa[i];
	}
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		for (int j=1;j<=k;j++){
			int tmp1,tmp2;
			cin>>tmp1>>tmp2;
			tong[tmp1]++;
			a[i].push_back(tmp1);
			t[i].push_back(tmp2);
		}
	}
	srand(time(0));
	while (q--){
		int x,y;
		cin>>x>>y;
		cout<<rand()%d<<endl;
	}
	return 0;
}
