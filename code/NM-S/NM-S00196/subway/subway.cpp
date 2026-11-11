#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,x,y;
struct station{
	int w;
	vector<pair<int,int>>road;
};
station st[N];
bool check(int id,int tat){
	if(tat==id)return false;
	for(int k=1;k<=st[tat].road.size();k++){
		int id1=st[tat].road[k].first;
		if(id1==id){
			return true;		
		}
	}
	return false;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>st[i].w;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			st[a].road.push_back({i,t}); 
		}
	}
	while(q--){
		cin>>x>>y;
		int maxx=0;
		int time=st[x].w;
		for(int i=1;i<=st[x].road.size();i++){ 
			int id=st[x].road[i].first;
			int ti=st[x].road[i].second;
			time+=ti;
			for(int j=1;j<=m;j++){
				if(check(id,j)){
 					time+=st[j].road[i].second;
					if(j==y){
						time+=st[j].w;
						maxx=max(maxx,time);
						time=st[x].w;
					}
				}
			}
		}
		cout<<maxx<<"\n"; 
	}

	return 0;
}
