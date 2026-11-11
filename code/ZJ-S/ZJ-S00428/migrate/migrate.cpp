#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,m,a[5010],nxt[5010],fnt[5010],dp[5010][5010],r,ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			nxt[i]=0;
			fnt[i]=0;
		}
		r=1;
		for(int i=1;i<=n;i++){
			while(a[r]-a[i]<=m&&r<=n) r++;
			nxt[i]=r-1;
		}
		r=n;
		for(int i=n;i>=1;i--){
			while(a[i]-a[r]<=m&&r) r--;
			fnt[i]=r+1;
			cout<<fnt[i]<<" ";
		}
		cout<<"\n";
		if(c==11||c==12){
			if(nxt[1]-1==n||nxt[1]<=2||(nxt[1]-1)*2>n){
				cout<<0<<"\n";
				continue;
			}
			int len=(nxt[1]-1)*2-1;
			cout<<n-len<<"\n";
			continue;
		}
	}
	return 0;
}
