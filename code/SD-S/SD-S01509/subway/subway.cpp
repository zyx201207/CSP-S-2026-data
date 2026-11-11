#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005];
vector<pair<long long,long long> >p[500005];
vector<int> bl[500005],con[505];
long long dij(long long s,long long t){
	long long ans[500005];
	for(int i=0;i<=m;i++){
		ans[i]=10000000000000000;
	}
	ans[s]=0;
	priority_queue<int,vector<int>,greater<int> >qu;
	qu.push(s);
	while(!qu.empty()){
		int u=qu.top();
		qu.pop();
		for(auto xx:p[u]){
			long long v=xx.first,ww=xx.second;
			if(ans[v]>ans[u]+ww){
				ans[v]=ans[u]+ww;
				qu.push(v);
			}
		}
	}
	return (ans[t]+w[s]+w[t]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		long long k,la=0,lt=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long a,b;
			cin>>a>>b;
			bl[a].push_back(i);
			bl[b].push_back(i);
			if(j>1){
				p[la].push_back({a,lt+b});
				p[a].push_back({la,lt+b});
			}
			la=a,lt=b;
		}
	}
	while(q--){
		long long s,t;
		cin>>s>>t;
		cout<<dij(s,t)<<'\n';
	}
	return 0;
}
