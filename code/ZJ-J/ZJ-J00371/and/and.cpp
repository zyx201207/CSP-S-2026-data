#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if(a[j]&(1<<i))cnt++;
		}
		if(cnt<m)continue;
		ans|=(1<<i);
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if(a[j]&(1<<i))continue;
			vis[j]=1;
		}
	}
	cout<<ans;
	return 0;
}
