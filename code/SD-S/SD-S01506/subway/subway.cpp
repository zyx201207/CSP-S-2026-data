#include<bits/stdc++.h>
#define int long long
using namespace std;

int c,n,m,d,q,minn=10000000,a[100002],b[1002][100002],k[100002],v[1002][100002],aa,bb;

int dfs(int qi,int ans){
	if(qi==bb){
		minn=min(minn,ans);
		return 1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(b[i][j]==qi+1){
				
				ans+=v[i][j]; 
				dfs(b[i][j],ans);
			}
			if(b[i][j]==aa){
					ans+=v[i][j];
			} 
		} 
	} 
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>b[i][j]>>v[i][j];			

		}
	}
	for(int i=1;i<=q;i++){
		cin>>aa>>bb;
		dfs(aa,0);
		cout<<minn+a[aa]+a[bb]<<'\n';
	} 
	return 0;
}

