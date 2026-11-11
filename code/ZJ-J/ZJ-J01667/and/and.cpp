#include<bits/stdc++.h>
using namespace std;
//pair<int,int> f[200005][2];
int a[200005];long long ans=-1;int n,m;
void dfs(long long x,int y,int k){
	if(k>=m){
		if(x<(1ll<<31)-1)ans=max(x,ans);
		return;
	}
	if(y>n)return;
	//cout<<x<<' '<<y<<' '<<k<<endl;
	dfs(x&a[y],y+1,k+1);
	dfs(x,y+1,k);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		f[i][1].first=1;
//		f[i][1].second=1;
	}
	/*for(int i=1;i<=n;i++){
		if(f[i][1].first<=f[i-1][1].first&a[i]){
			f[i][1].first=f[i-1][1].first&a[i];
			f[i][1].second=f[i-1][1].second+1;
			if(f[i][1].second==m)ans=max(ans,f[i][1].first);
		}
		if(f[i][1].first<=f[i-1][0].first&a[i]){
			f[i][1].first=f[i-1][0].first&a[i];
			f[i][1].second=f[i-1][0].second+1;
			if(f[i][1].second==m)ans=max(ans,f[i][1].first);
		}
		if(f[i][0].first<=f[i-1][1].first){
			f[i][0].first=f[i-1][1].first;
			f[i][0].second=f[i-1][1].second;
			if(f[i][0].second==m)ans=max(ans,f[i][0].first);
		}
		if(f[i][0].first<=f[i-1][0].first){
			f[i][0].first=f[i-1][0].first;
			f[i][0].second=f[i-1][0].second;
			if(f[i][0].second==m)ans=max(ans,f[i][0].first);
		}
	}*/
	dfs((1ll<<31)-1,1,0);
	cout<<ans;
	return 0;
	
} 
