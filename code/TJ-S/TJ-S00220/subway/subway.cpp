#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int kou_ting[500005];
vector<pair<int,int> > vec[500005];
int zhantai[500002];
int ew;
int newname[20002][2002];
int danci;
int vis[500002];
int gt(int x,int y){
	priority_queue<pair<int,int> > p;
	p.push(make_pair(0,x));
	while(!p.empty()){
		auto u=p.top();
		p.pop();
		vis[u.second]=1;
		for(auto v:vec[u.second]){
			if(v.first==y) return u.first+v.second;
			if(!vis[v.first]){
				p.push(make_pair(u.first+v.second,v.first));
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>kou_ting[i];
	}
	ew=m;
	for(int i=1;i<=n;i++){
		int kk;
		cin>>kk;
		vector<pair<int,int> > tmp;
		for(int j=1;j<=kk;j++){
			int x,y;
			cin>>x>>y;
			danci=y;
			tmp.push_back(make_pair(x,y));
			
		}
		for(int j=1;j<=kk;j++){
			int aa=j;
			zhantai[j]++;
			newname[j][zhantai[j]]=aa;
			if(!vec[j].empty()){
				aa=++ew; 
				newname[j][zhantai[j]]=aa;
				for(int k=1;k<zhantai[j];k++){
					int v=newname[j][k];
					vec[aa].push_back(make_pair(v,1));
					vec[v].push_back(make_pair(aa,1));
				}
			} 
			for(auto v:tmp){
				if(v.first==j) continue;
				pair<int,int> pi;
				pi.first=v.first;
				pi.second=0;
				vec[aa].push_back(pi);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		memset(vis,0,sizeof(vis));
		cout<<gt(x,y)*danci+kou_ting[x]+kou_ting[y]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
