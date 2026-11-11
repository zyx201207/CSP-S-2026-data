#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int,int> >lines[505];
vector<int>stations;

vector<pair<int,int> > tu[1005];

int c,n,m,d,q;

int visited[1005],dis[1005];

int d7(int st,int en){
	for(int i=1;i<=n;i++){
		if(lines[i].size()==2){
			int s1=lines[i][0].first;
			int s2=lines[i][1].first;
			int t1=lines[i][0].second;
			int t2=lines[i][1].second;
			tu[s1].push_back({s2,t1+t2});
			tu[s2].push_back({s1,t1+t2});
		}
	}
	memset(dis,0xf,sizeof(dis));
	memset(visited,0,sizeof(visited));
	visited[st]=1;
	dis[st]=0;
	for(int i=0;i<tu[st].size();i++){
		dis[tu[st][i].first]=tu[st][i].second;
	}
	for(int k=1;k<n;k++){
		int mn=0,minw=0;
		for(int i=1;i<=n;i++){
			if(!visited[i] && dis[i]<mn){
				mn=dis[i];
				minw=i;
			}
		}
		visited[minw]=1;
		for(int i=0;i<tu[st].size();i++){
			dis[tu[minw][i].first]=min(dis[tu[minw][i].first],tu[minw][i].second+dis[minw]);
		}
		if(minw==en)return dis[minw];
	}
}

signed main(){
	freopen("subway4.in","r",stdin);
	//freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	stations.push_back(0);
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		stations.push_back(w);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			lines[i].push_back({a,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		//if(c>=7 && c<=11)
		cout<<d7(x,y)+stations[x]+stations[y]<<endl;
	}
	return 0;
}
