#include<bits/stdc++.h>
using namespace std;
long long t,n,m,cnt,mx=1,c,d,q,x,x1,k1,xr,yr,T;
long long w[500005],w1[500005],w2[500005];
long long dis[2005][2005];
bool vis[500005];
struct node{
	long long y,z;
};
queue<long long> qx;
vector<long long> v2[500005];//每个地铁站所对应的线路 
vector<node> v1[505];//每条线路 
vector<node> v[500005];// 每个地铁站所能直接到达的其他地铁站和价格 

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
//	if(c>=12&&c<=19){
//		for(int i=1;i<=m;i++){
//			cin>>w[i];
//		}
//		for(int i=1;i<=n;i++){
//			cin>>k;
//			for(int j=1;j<=k;j++){
//				cin>>x>>T; 
//				v[x].push_back(i);
//				v1[i].push_back(x,T);
//			}
//		}
//		while(!qx.empty()){
//			int x=qx.top();
//			
//		}
//		
//		
//		
//		return 0;
//	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k1;
		for(int j=1;j<=k1;j++){
			cin>>x>>x1; 
			v2[x].push_back(i);
			v1[i].push_back({x,x1});
		}
	}
	if(n==1&&c>=20){
		for(int i=0;i<v1[1].size();i++){
			w1[v1[1][i].y]=v1[1][i].z;
		}
		for(int i=1;i<=q;i++){
			cin>>xr>>yr;
			cout<<w[xr]+w[yr]+w1[xr]+w1[yr];
		}
		
		
		return 0;
	}
	if(n==2&&c>=20){
		for(int i=0;i<v1[1].size();i++){
			w1[v1[1][i].y]=v1[1][i].z;
		}
		for(int i=0;i<v1[2].size();i++){
			w2[v1[2][i].y]=v1[2][i].z;
		}
		long long mn=1e18;
		for(int i=1;i<=m;i++){
			mn=min(mn,w1[i]+w2[i]);
		}
		for(int i=1;i<=q;i++){
			cin>>xr>>yr;
			cout<<min(w[xr]+w[yr]+w2[xr]+w2[yr],min(min(w[xr]+w[yr]+w1[xr]+w1[yr],mn+w[xr]+w[yr]+w1[xr]+w2[yr]),w[xr]+w[yr]+w1[yr]+w2[xr]+mn));
		}
		
		return 0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		int xxx=0;
		
		for(int j=0;j<v2[i].size();j++){
			for(int k=0;k<v1[v2[i][j]].size();k++){
				if(v1[v2[i][j]][k].y==i){
					xxx=v1[v2[i][j]][k].z;
				}
			}
			for(int k=0;k<v1[v2[i][j]].size();k++){
				if(v1[v2[i][j]][k].y!=i) v[i].push_back({v1[v2[i][j]][k].y,v1[v2[i][j]][k].z+xxx});
			}
		} 
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			dis[i][v[i][j].y]=min(dis[i][v[i][j].y],v[i][j].z); 
		}
	} 
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(int i=1;i<=m;i++) vis[i]=1;
	for(int i=1;i<=m;i++) qx.push(i);
	while(!qx.empty()){
		int k=qx.front();
		vis[k]=0;
		qx.pop();
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
					if(vis[j]==0){
						qx.push(j);	
						vis[j]=1;
					}
				}
			} 
		}
	}
	
	for(int i=1;i<=q;i++){
		cin>>xr>>yr;
//		cout<<dis[xr][yr]<<' ';
		cout<<dis[xr][yr]+w[xr]+w[yr]<<'\n'; 
	}
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<v[i].size();j++){
//			cout<<v[i][j].y<<' '<<v[i][j].z<<' ';
//		}
//		cout<<'\n';
//	}	
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	return 0;
} 



