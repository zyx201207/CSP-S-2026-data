#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=2e3+5;
int c,t,n,k,used[N],ans,dis[N][N],mm[N];
vector<int> ve[N],v;
void go(int f){
	if(v.size()==k){
		ans=min(ans,f);
		return;
	}
	for(int i=1;i<=n;i++){
		if(used[i])continue;
		int minn=INT_MAX,maxx=0;
		for(int j:v){
			if(dis[i][j]<minn)minn=dis[i][j];
			if(dis[i][j]>maxx)maxx=dis[i][j];
		}
		if(minn!=1||maxx>=mm[v.size()+1])continue;
		v.push_back(i);used[i]=1;
		go(max(maxx,f));
		used[i]=0;v.pop_back();
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)ve[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				dis[i][j]=INT_MAX;
			}
		}
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		ve[u].push_back(v);
		ve[v].push_back(u);
		dis[u][v]=1;
		dis[v][u]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
			}
		}
	}
	ans=INT_MAX;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			for(int p=1;p<=k;p++)mm[p]=INT_MAX;
			v.push_back(i);
			v.push_back(j);
			go(dis[i][j]);
			v.clear();
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10*/