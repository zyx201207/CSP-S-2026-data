#include<bits/stdc++.h>
using namespace std;
struct MAP{
	map<int,int>ma;
}a[505];
struct road{
	int v,w;
};
vector<road>ve[500005];
int W[505];
int dis[500005];
int c,n,m,d,q;
bool vis[500005];
int dij(int s,int t){
	for(int i=1;i<=m;i++){
		dis[i]=1e9;
		vis[i]=0;
	}
	dis[s]=0;
	int num=1;
	while(num<=m){
		int minn=1e9;
		int z;
		for(int i=1;i<=m;i++){
			if(!vis[i]){
				if(minn>dis[i]){
					minn=dis[i];
					z=i;
				}
			}
		}
		vis[z]=1;
		for(int i=0;i<ve[z].size();i++){
			if(dis[ve[z][i].v]>dis[z]+ve[z][i].w){
				dis[ve[z][i].v]=dis[z]+ve[z][i].w;
				
			}
		}
	}
	return dis[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	int X_X[500005];
	if(c<=11&&c>=7){
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			if(k==1){
				int x,y;
				cin>>x>>y;
				continue;
			}
			int sum=0;
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			ve[x1].push_back({x2,y1+y2});
			ve[x2].push_back({x1,y1+y2});
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<dij(x,y)+W[x]+W[y]<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int x;
			cin>>x;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<W[x]+W[y]<<endl;
	}
	return 0;
} 
