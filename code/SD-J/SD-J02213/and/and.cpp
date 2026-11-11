#include<bits/stdc++.h>
using namespace std;
long long a[200010],vis[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=31;i>=0;i--){
		long long cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==0&&(a[j]>>i&1)==1)	cnt++;
		}
		if(cnt<m)	continue;
		ans+=(1ll<<i);
		for(int j=1;j<=n;j++){
			if((a[j]>>i&1)==0)	vis[j]=1;
		}
	}
	cout<<ans;
	return 0;
}

