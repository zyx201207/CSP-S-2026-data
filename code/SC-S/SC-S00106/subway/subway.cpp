#include<bits/stdc++.h>
#define PII pair<int,int>
#define ll long long
using namespace std;
const int N=5050;
int w[N];
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	vector<vector<PII>> vec(n+1);
	for(int i=1;i<=n;i++){
		int a,t;
		cin>>a>>t;
		vec[i].push_back({a,t});
		vec[a].push_back({i,t});
	}
	if(n==1)
		for(int i=1;i<=q;i++)cout<<0<<'\n';
	else if(n==2){
		int ans=w[1]+w[2];
		int mi=0;
		for(auto x:vec[1])
			mi=min(mi,x.second);
		ans+=mi;
		for(int i=1;i<=q;i++)cout<<ans<<'\n';
	}else{
		int ans1=w[1]+w[2];
		int mi1=1e9;
		for(auto x:vec[1])
			if(x.first==2)mi1=min(mi1,x.second);
		int ans2=w[1]+w[3];
		int mi2=1e9;
		for(auto x:vec[1])
			if(x.first==3)mi2=min(mi2,x.second);
		int ans3=w[2]+w[3];
		int mi3=1e9;
		for(auto x:vec[2])
			if(x.first==3)mi3=min(mi3,x.second);
		for(int i=1;i<=q;i++){
			int u,v;
			cin>>u>>v;
			if(u==v)cout<<0<<'\n';
			if(u==1 && v==2 || u==2 && v==1)cout<<ans1+mi1<<'\n';
			if(u==1 && v==3 || u==3 && v==1)cout<<ans2+mi2<<'\n';
			if(u==2 && v==3 || u==3 && v==2)cout<<ans3+mi3<<'\n';
		}
	}
//	for(int i=1;i<=m;i++)road[i][i]=0;
//	for(int i=1;i<=n;i++){
//		int k;
//		cin>>k;
//		for(int j=1;j<=k;j++){
//			int a,t;
//			cin>>a>>t;
//			road[i][a]=t;
//			road[a][i]=t;
//		}
//	}
//	for(int k=1;k<=n;k++)
//		for(int i=1;i<=n;i++)
//			for(int j=i+1;j<=n;j++)
//				road[i][j]=min(road[i][j],road[i][k]+road[j][k]+w[i]+w[j]);
//	for(int i=1;i<=q;i++){
//		int u,v;
//		cin>>u>>v;
//		cout<<road[u][v]+w[u]+w[v]<<'\n';
//	}
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