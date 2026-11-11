#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
struct node{
	int zhan,xian,to_xian;
};
struct Node{
	int s,f;
};
vector<int> time_zhan[500];
vector<node> G[500005];
vector<int> zhanting;
vector< Node > jihua;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	zhanting.resize(m+1);
	for(int i=1;i<=m;i++){
		cin>>zhanting[i];
	}
	int k,x,y;
	cin>>k>>x>>y;
	jihua.resize(p+1);
	for(int i=2;i<=k;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		time_zhan[1].push_back(b);
		node p;
		p.zhan=a;
		p.xian=1;
		p.to_xian=1;
		G[x].push_back(p);
		
	}
	for(int i=2;i<=n;i++){
		cin>>k;
		cin>>x>>y;
		for(int j=2;j<=k;j++){
			int a,b;
			scanf("%d%d",&a,&b);
			node p;
			p.zhan=a;
			p.xian=i;
			p.to_xian=i;
			G[x].push_back(p);
			time_zhan[i].push_back(b);
			if(G[x].size()>0){
				for(int i=0;i<G[x].size();i++){
					node r;
					r.zhan=a;
					r.xian=i;
					r.to_xian=G[x][a].xian;
					G[x].push_back(r);
				}
			}
		}
	}
	for(int i=1;i<=p;i++){
		scanf("&d&d",&jihua[i].s,&jihua[i].f);
	}
	
}
