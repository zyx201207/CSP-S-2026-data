#include<bits/stdc++.h>
#define int long long
using namespace std;
int maxn,n,m,a[200005];
bool p=1,vis[200005];
void dfs(int d,int kk) {
	if(d==m+1) {
		maxn=max(kk,maxn);
	} else {
		for(int i=1; i<=n; i++) {
			if(!vis[i]) {
				int tkk;
				if(d==1) {
					tkk=a[i];
				} else {
					tkk=kk&a[i];
				}
				vis[i]=1;
				dfs(d+1,tkk);
				vis[i]=0;
			}
		}
	}
}
bool zz(int ttt) {
	
	while(ttt!=0){
		if(ttt%2==0||ttt==1){
			ttt/=2;
		}else{
			return false;
		}
	}
	return true;
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		maxn=max(a[i],maxn);
		if(!zz(a[i]+1)) {
			p=0;
		}
	}
	if(m==1) {
		cout<<maxn;
	} else if(m==2) {
		maxn=0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(i!=j) {
					maxn=max(maxn,a[i]&a[j]);
				}
			}
		}
		cout<<maxn;
	} else if(m==n) {
		int ans=a[1];
		for(int i=1; i<=n; i++) {
			ans=ans&a[i];
		}
		cout<<ans;
	} else if(p) {
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	} else if(m==n-1){
		maxn=0;
		int ans;
		for(int i=1;i<=n;i++){
			ans=a[1];
			if(i==1){
				ans=a[2];
			}
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}else{
					ans=ans&a[i];
				}
			}
			maxn=max(ans,maxn);
		}
		cout<<maxn;
	} else{
		int d=1;
		maxn=0;
		dfs(d,0);
		cout<<maxn;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
