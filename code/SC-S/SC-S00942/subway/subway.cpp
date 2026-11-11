#include<bits/stdc++.h>

using namespace std;
int n;int m;int d;int q;
long long w[500010];int k[510];
long long dis[1010][510];
long long dis1[1010];bool hsh[1010];
int xl[1010][510];
long long dij(int x){
	long long maxv=pow(10,18);
	for(int i=1;i<=1000;i++){
		dis1[i]=maxv;
	}
	memset(hsh,0,sizeof(hsh));
	priority_queue<pair<long long,int> > q;
	q.push({0,x});hsh[x]=0;dis1[x]=0;
	while(!q.empty()){
		pair<long long,int> tmp=q.top();q.pop();
		int z=tmp.second;long long v=tmp.first;
		if(hsh[z]==1){
			continue;
		}hsh[z]=1;
		for(int i=1;i<=xl[z][0];i++){
			for(int j=1;j<=m;j++){
				if(dis[j][xl[z][i]]!=maxv){
					if(dis[j][xl[z][i]]+v+dis[z][xl[z][i]]>dis1[j]){
						dis1[j]=dis[j][xl[z][i]]+v+dis[z][xl[z][i]];
						if(hsh[j]==0){
							q.push({dis1[j],j});
						}
					}
				}
			}
		}
	} 
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}long long maxv=pow(10,18);
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=500;j++){
			dis[i][j]=maxv;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int i=1;i<=k[i];i++){
			int x;cin>>x;
			int y;cin>>y;
			dis[x][i]=y;
			xl[x][0]++;xl[x][xl[x][0]]=i;
		}
	}
	while(q--){
		int x;int y;
		cin>>x>>y;
		dij(x);
		cout<<w[x]+dis1[y]+w[y]<<endl;
	}
	
	
	
	
	
	return 0;
}