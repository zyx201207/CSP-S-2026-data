#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
using namespace std;
const int N=2e5+5;
int c,n,m,d,q,x,y,k,ans,h[N],t[N],a[N];
bool isvis[N];
vector<pair<int,int> > vt[N];
int solve(int x,int y){
	memset(isvis, false, sizeof isvis);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,x});
	isvis[x]=true;
	while(!q.empty()){
		pair<int,int> hk=q.top();
		q.pop();
		if(hk.second==y){
			return hk.first;
		}
		for(auto u : vt[hk.second]){
			if(isvis[u.first])	continue;
			isvis[u.first]=1;
			q.push({hk.first+u.second, u.first});
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; ++i){
		cin>>a[i];
	}
	for(int i=1; i<=n; ++i){
		cin>>k;
		for(int j=1; j<=k; ++j){
			cin>>h[j]>>t[j];
			for(int e=j-1; e>=1; --e){
				vt[h[e]].push_back({h[j],t[e]+t[j]});
				vt[h[j]].push_back({h[e],t[e]+t[j]});
			}
		}
	}
	while(q--){
		cin>>x>>y;
		ans=a[x]+a[y]+solve(x,y);
		cout<<ans<<'\n';
	}
	return 0;
}

