#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inff=1e18;

int ccc,n,m,d,q,w[500005],ans[2005][2005],v[500005],tt[500005][3];
bool vv[500005];
vector<pair<int,int> >e[500005];

void bfs(int s){
	priority_queue<pair<int,int> >que;
	for(int i=1;i<=m;i++)v[i]=inff;
	v[s]=0;que.push({0,s});
	while(que.size()){
		int x=que.top().second;que.pop();
		int ss=e[x].size();
		for(int i=0;i<ss;i++){
			int j=e[x][i].first,k=e[x][i].second;
			if(v[j]>v[x]+k){
				v[j]=v[x]+k;
				que.push({-v[j],j});
			}
		}
	}
	for(int i=1;i<=m;i++)ans[s][i]=v[i];
}

void bfs1(int s){
	queue<pair<int,int> >que;
	for(int i=1;i<=m;i++){
		v[i]=inff;
		vv[i]=0;
	}
	v[s]=0;que.push({0,s});
	while(que.size()){
		int x=que.front().second;que.pop();
		vv[x]=1;
		int ss=e[x].size();
		for(int i=0;i<ss;i++){
			int j=e[x][i].first,k=e[x][i].second;
			if(v[j]>v[x]+k&&!vv[j]){
				v[j]=v[x]+k;
				que.push({v[j],j});
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ccc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	if(n<=2&&m>=2000){
		int mnn=inff;
		for(int i=1;i<=n;i++){
			int p;cin>>p;
			for(int j=1;j<=p;j++){
				int x,y;cin>>x>>y;
				tt[x][i]=y;
			}
		}
		for(int i=1;i<=m;i++){
			if(tt[i][1]&&tt[i][2])mnn=min(mnn,tt[i][1]+tt[i][2]);
		}
		while(q--){
			int x,y,aaa=inff;cin>>x>>y;
			for(int i=1;i<=2;i++){
				for(int j=1;j<=2;j++){
					if(i==j){
						if(tt[x][i]&&tt[y][j])aaa=min(aaa,tt[x][i]+tt[y][j]);
					}
					else{
						if(tt[x][i]&&tt[y][j])aaa=min(aaa,tt[x][i]+tt[y][j]+mnn);
					}
				}
			}
			aaa+=w[x]+w[y];
			cout<<aaa<<endl;
		}
	}
	else{
		for(int ttt=1;ttt<=n;ttt++){
			int p;cin>>p;
			vector<int>s1,s2;
			for(int i=1;i<=p;i++){
				int x,y;cin>>x>>y;
				s1.push_back(x);
				s2.push_back(y);
			}
			for(int i=0;i<p;i++){
				for(int j=0;j<p;j++){
					if(i==j)continue;
					e[s1[i]].push_back({s1[j],s2[i]+s2[j]});
				}
			}
		}
		if(m<=2000){
			for(int i=1;i<=m;i++)bfs(i);
			while(q--){
				int x,y;cin>>x>>y;
				int aaa=ans[x][y]+w[x]+w[y];
				cout<<aaa<<endl;
			}
		}
		else{
			while(q--){
				int x,y;cin>>x>>y;
				bfs1(x);
				int aaa=v[y]+w[x]+w[y];
				cout<<aaa<<endl;
			}
		}
	}
	
	return 0;
}
