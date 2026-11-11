#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans[300010],vis[300010],dis[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=n;i>=1;i--){
		if(!vis[a[i]]) vis[a[i]]=i;
	}
	for(long long i=1;i<=n;i++){
		ans[a[i]]+=dis[i-1]+1;
		dis[vis[a[i]]]+=dis[i-1]+1;
	}
	for(long long i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}