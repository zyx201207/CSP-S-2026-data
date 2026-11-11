#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],ans,K,k1[500005],k2[500005],k5,k6,v[500005];
vector<pair<int,int> >k[500005];
void dfs(int x){
	for(int i=0;i<k[x].size();i++){
		long long h=k[x][i].first,t=k[x][i].second;
		if(v[x]+t>=v[h])
		continue;
		v[h]=v[x]+t;
		dfs(h);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>K;
		for(int j=1;j<=K;j++){
			cin>>k1[j]>>k2[j];
		}
		for(int j=1;j<=K;j++){
			for(int v=j+1;v<=K;v++){
				k[k1[j]].push_back({k1[v],k2[j]+k2[v]});
				k[k1[v]].push_back({k1[j],k2[j]+k2[v]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>k5>>k6;
		for(int j=1;j<=m;j++)
		v[j]=1e18;
		v[k5]=0;
		dfs(k5);
		cout<<v[k6]+w[k5]+w[k6]<<endl;
	}
	return 0;
}
