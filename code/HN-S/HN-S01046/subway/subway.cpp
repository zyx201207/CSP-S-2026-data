#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
ll c,n,m,d,p,w[N],dis[N],res[1010][1010];
struct node{
	ll to,val;
};
priority_queue<pair<ll,ll>>q;
vector<node>e[N];
void dij(){
	while(!q.empty()){
		auto mow=q.top();
		q.pop();
		int u=mow.second;
		for(auto now:e[u]){
			int x=now.to;
			int y=now.val;
			if(dis[x]>dis[u]+y){
				dis[x]=dis[u]+y;
				q.push({-dis[x],x});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int x;
	int y,z;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>y>>z;
			node l;
			l.to=y;
			l.val=z;
			e[m+i].push_back(l);
			l.to=m+i;
			e[y].push_back(l);
		}
	}
	if((c<=8&&c>=1)||(c<=15&&c>=12)){
		for(int i=1;i<=p;i++){
			cin>>x>>y;
			for(int j=1;j<=n+m;j++){
				dis[j]=1e17;
			}
			dis[x]=0;
			q.push({0,x});
			dij();
			cout<<dis[y]+w[x]+w[y]<<"\n";
		}
	}
	else{
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n+m;j++){
				dis[j]=1e17;
			}
			dis[i]=0;
			q.push({0,i});
			dij();
			for(int j=1;j<=m;j++){
				res[i][j]=dis[j];
			}
		}
		for(int i=1;i<=p;i++){
			cin>>x>>y;
			cout<<res[x][y]+w[x]+w[y]<<"\n";
		}
	}
	return 0;
}
