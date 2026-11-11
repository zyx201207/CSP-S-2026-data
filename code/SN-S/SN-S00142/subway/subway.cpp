#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int INF=INT_MAX;
long long c,n,m,d,q,ans,x,y,w[N],a[505][1005],t[505][1005],vis[505][1005],minn=INF;
void dfs(long long tt,long long anss){
	for(int i=1;i<=m;i++){
		if(i!=tt&&t[tt][i]!=0&&vis[tt][i]==0){
			anss+=t[tt][tt]; 
			anss+=t[tt][i];
//			cout<<t[tt][tt]<<" "<<t[tt][i]<<" ";
			if(i==y){
				minn=min(minn,anss);
				continue;
			} 
			vis[tt][i]=1;
			long long x=i,ans=anss;
			dfs(x,ans);
			vis[tt][i]=0;
		}
	} 
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int p=1;p<=k;p++){
			t[i][p]=0; 
		}
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];		
		}
	}
	while(q--){
		ans=0;
		cin>>x>>y;
		ans+=w[x];
		ans+=w[y];
		dfs(x,ans);
		cout<<minn<<endl;
	}
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
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
