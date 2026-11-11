#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500001],v[500001],b[500001];
struct A{
	int a,t1,t2;
};
long long dis[501][501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	/*for(int i=1;i<=n;i++){
		int k;cin>>k;
		int aa,tt,a1;
		cin>>aa>>tt;
		b[aa].push_back({aa,0,tt});
		if(int(b[aa].size())){
			for(int j=0;j<int(b[aa].size();j++))b[aa].push_back({aa,b[aa][j].t2+tt,tt});
		}
		for(int i=2;i<=k;i++){
			cin>>a1>>tt;
			if(int(b[a1].size())){
				for(int j=0;j<int(b[a1].size();j++))b[a1].push_back({a1,b[a1][j].t2+tt,tt});
			}
			b[aa].push_back({a1,0,tt});
			aa=a1;
		}
	}*/
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		int aa,tt,a1;
		cin>>aa>>tt;
		b[aa]=tt;
		for(int j=2;j<=k;j++){
			cin>>a1>>tt;
			if(b[aa]){
				dis[aa][a1]=b[aa]+tt;
				dis[a1][aa]=b[aa]+tt;
			}
			b[aa]=tt;
			//b[aa]=min(b[aa],tt);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;cin>>u>>v;
		if(u>v)swap(u,v);
		cout<<w[u]+w[v]+b[u]+b[v]+dis[u][v]<<"\n";
	}
	return 0;
}//orz
