#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool v[500505];
int c,n,m,D,Q,k[505];
ll w[500005],d[500505];
vector<int>e[500505];
vector<ll>l[500505];
//multiset<pair<int,ll>>q;
priority_queue<pair<int,ll>>q;
void dij(int s){
	q.push({0,s});
	pair<int,ll> f={0,s};
	d[s]=0;
	while(!q.empty()){
		f=q.top();
		q.pop();
//		ll x=f.first;
		int y=f.second;
		if(v[y])continue;
		v[y]=1;
		for(int i=0;i<e[y].size();i++){
			int z=e[y][i],dis=l[y][i];
			if(d[z]>d[y]+dis){
				d[z]=d[y]+dis;
				q.push({-d[z],z});
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,b;
			cin>>a>>b;
			e[a+n].push_back(i);
			l[a+n].push_back(b);
			e[i].push_back(a+n);
			l[i].push_back(b);
		}
	}
	while(Q--){
		for(int i=0;i<=n+m;i++)d[i]=0x3f3f3f3f3f3f3f3f,v[i]=0;
		int a,b,c;
		cin>>a>>b;
		c=w[a]+w[b],a+=n,b+=n;
		dij(a);
		cout<<d[b]+c<<"\n";
	}
	return 0;
}
