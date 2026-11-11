#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,w[500005],x,y,t;
vector<pair<int,int>>sta[500005];
long long a[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(a,0x3f,sizeof(a));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>t;
			sta[x].push_back(make_pair(i,t));
		}	
	}
	long long inf=a[1][1];
	for(int i=1;i<=n;i++)	a[i][i]=0;
	for(int i=1;i<=m;i++)
		for(pair<int,int> j:sta[i])
			for(pair<int,int> w:sta[i])
				a[j.first][w.first]=min(a[j.first][w.first],(long long)j.second+w.second);
	for(int w=1;w<=n;w++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)	a[i][j]=min(a[i][j],a[i][w]+a[w][j]);
	while(q--){
		cin>>x>>y;
		long long ans=inf;
		for(pair<int,int> i:sta[x])
			for(pair<int,int> j:sta[y])
				ans=min(ans,a[i.first][j.first]+i.second+j.second);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
