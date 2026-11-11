#include<bits/stdc++.h>
using namespace std;
int n,m,nown,a[200010],ans=(1<<30)-1;
bool vis[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	nown=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==1) continue;
			if((a[j]>>i)&1) cnt++;
		}
		if(cnt<m) continue;
		for(int j=1;j<=n;j++)
			if(!((a[j]>>i)&1)) vis[j]=1;
	}
	for(int i=1;i<=n;i++)
		if(vis[i]==0) ans&=a[i];
	cout<<ans;
	return 0;
}