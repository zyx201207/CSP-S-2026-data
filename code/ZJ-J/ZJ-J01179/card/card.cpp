#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[300005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;long long c[m+5]={0};
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		long long vis[m+5]={0},d[n+5]={0};bool p[m+5]={0};
		for(int j=i;j<=n;++j){
			if(vis[a[j]]) d[vis[a[j]]]=j,vis[a[j]]=0;
			else vis[a[j]]=j;
		}
		for(int j=i;j<=n;++j){
			ans[a[j]]+=!(p[a[j]]);
			p[a[j]]=true;
			if(d[j]){
				j=d[j];
			}	
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<' ';
	}
	
	return 0;
}