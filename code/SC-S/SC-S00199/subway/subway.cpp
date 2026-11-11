#include<bits/stdc++.h>//0
using namespace std;
int w[200002];
int k[505];
int a[505][50005];
int t[505][50005];
vector<int>z[500005];//第i地铁口可到的路线有哪些
int bfs(int u,int y){
	int dao[500005];//到……地铁站的时间
	dao[u]=w[u];
	queue<int>du;//l1
	du.push(u);
	while(!du.empty()){
		int dd=du.front();
		du.pop();
		for(auto xian:z[dd]){
			for(int o=1;o<=k[xian];o++){//a[xian][o] 这条线经过的第o个站
				if(dao[a[xian][o]]==0||dao[a[xian][o]]>dao[dd]+t[xian][o]){
					dao[a[xian][o]]=dao[dd]+t[xian][o];
					du.push(a[xian][o]);
				}
			}
		}
	}
	return dao[y]+w[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			z[a[i][j]].push_back(i);//z[i]：可到的线路有哪些
		}
	}
	for(int r=1;r<=q;r++){
		int x,y;
		cin>>x>>y;
		cout<<bfs(x,y)<<"\n";
	}
	return 0;
}
/*
从i号线到x站:
t[i][(x)]
总：站口->站厅：w[x]+[y]
站厅->i号线：t[a[i][l1]][i]
站厅u到站厅v（第i线）:t[a[i][l1]][i]+t[a[i][l2]][i]
a[i][l1]=u;
a[i][l2]=v;
*/