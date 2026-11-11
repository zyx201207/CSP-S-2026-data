#include<bits/stdc++.h>
using namespace std;
int holl_to_station[15000][510];//站a到线b的时间
int holl_to_door[15000];
vector<long long> line_through_station[15000];//过站a的线
vector<long long> station_on_line[15000];//线b过的站
unsigned int way[13000][13000];
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(way,0x3f,sizeof(way));//0x3f3f3f3f;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>holl_to_door[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			line_through_station[a].push_back(i);
			station_on_line[i].push_back(a);
			holl_to_station[a][i]=t;
		}
	}
	for(int i=1;i<=m;i++){
		for(auto line:line_through_station[i]){
			for(auto sta:station_on_line[line]){
				if(sta!=i){
					way[i][sta]=holl_to_station[sta][line]+holl_to_station[i][line];
				}
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				way[i][j]=min(way[i][j],way[i][k]+way[k][j]);
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		long long ans=0;
		int x,y;
		cin>>x>>y;
		ans+=(holl_to_door[x]+holl_to_door[y]);
		ans+=way[x][y];
		cout<<ans<<"\n";
	}
	
	return 0;
}