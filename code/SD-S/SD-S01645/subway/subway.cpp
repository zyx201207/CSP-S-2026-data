#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Node{
	int y,q;
};int m,n,d,q;
vector<Node>v[500010];
int a[500010];
int dot[500010][210];
map<pair<int,int>,int>mp;
int id;
int num[500010];
vector<int>bl[500010];
bool vit[500010];
long long dis[500010];
int dij(int s,int e){
	long long mins=1e18;
	for(int st=0;st<bl[s].size();st++){
		for(int i=1;i<=id;i++){
			dis[i]=1e18;
			vit[i]=0;
		}
		dis[mp[{bl[s][st],s}]]=0;
		priority_queue<int>q;
		q.push(mp[{bl[s][st],s}]);vit[mp[{bl[s][st],s}]]=1;
		while(!q.empty()){
			int top=q.top();
			q.pop();
			vit[top]=1;
			for(Node u:v[top]){
				if(vit[u.y])continue;
				if(dis[top]+u.q<dis[u.y]){
					dis[u.y]=dis[top]+u.q;
					vit[u.y]=1;
					q.push(u.y);
				}
			}
		}
		for(int ed=0;ed<bl[e].size();ed++){
			int eid=mp[{bl[e][ed],e}];
			mins=min(mins,dis[eid]+dot[s][bl[s][st]]+dot[e][bl[e][ed]]);
		}
	}return mins;
}
signed main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c;
	cin>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=m;i++){
		int su;
		cin>>su;
		int lt=0;
		while(su--){
			int k,r;
			cin>>k>>r;
			dot[k][i]=r;
			mp[{i,k}]=++id;
			num[k]++;
			bl[k].push_back(i);
			if(lt){
				v[lt].push_back({id,0});
				v[id].push_back({lt,0});
			}//cout<<lt<<' '<<id<<'\n';
			lt=id;
			
		}
	}/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cout<<dot[i][j]<<' ';
		}cout<<'\n';
	}
	*/
	for(int i=1;i<=n;i++){
		for(int j=0;j<bl[i].size();j++){
			for(int k=j+1;k<bl[i].size();k++){
				v[mp[{bl[i][j],i}]].push_back({mp[{bl[i][k],i}],dot[i][bl[i][j]]+dot[i][bl[i][k]]});
				v[mp[{bl[i][k],i}]].push_back({mp[{bl[i][j],i}],dot[i][bl[i][j]]+dot[i][bl[i][k]]});
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(Node j:v[i]){
			cout<<j.y<<' '<<j.q<<' ';
		}cout<<'\n';
	}*/
	while(q--){
		int s,e;
		cin>>s>>e;
		cout<<dij(s,e)+a[s]+a[e]<<'\n';
	}
	return 0;
}
