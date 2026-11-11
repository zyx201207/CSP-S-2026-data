#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005];
long long k;
vector <long long> edge[10000005];
long long time[505][20005];
long long ans;
long long dfs(long long first,long long now,long long sum,long long pa){
	for(int i=0;i<edge[now].size();i++){
		if(edge[now][i]!=pa){
			dfs(first,edge[now][i],sum+=w[edge[now][i]],now);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		int a[20005];
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[i][j];
			edge[a[j-1]].push_back(a[j]);
			edge[a[j]].push_back(a[j-1]);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=0;
		ans=dfs(x,y,w[y],0);
		cout<<ans<<endl;
	}
	return 0;
}
