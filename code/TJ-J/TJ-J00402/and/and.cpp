#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,m,a[N],mx;
bool vis[N];
void dfs(int pos,int num,int now) {
	if(num==0) {
		num=m-1;
		vis[pos]=1;
		mx=max(mx,now);
		return;
	}
	for(int i=pos; i<=n; i++) {
		if(vis[i]==0) {
			now&=a[i],vis[i]=1;
			memset(vis,0,sizeof vis);
			dfs(pos,num-1,now);
		}
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	if(m==1) {
		for(int i=1; i<=n; i++) mx=max(a[i],mx);
		cout<<mx<<endl;
		return 0;
	}
	if(m==n) {
		mx=a[1];
		for(int i=2; i<=n; i++) mx&=a[i];
		cout<<mx<<endl;
		return 0;
	}

	for(int i = 1; i<=n; i++) {
		memset(vis,0,sizeof vis);
		vis[i] = 1;
		dfs(i,m-1,a[i]);
	}
	cout<<mx<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//#include<bits/stdc++.h>
//#define pii pair<int,int>
//using namespace std;
//const int N = 2e5+5;
//int n,m,a[N];
//pii dp[N];
//int main() {
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
//	scanf("%d %d",&n,&m);
//	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
//	dp[1].first=a[1];
//	for(int i=1; i<=n; i++) dp[i].second=m;
//	for(int i=2; i<=n; i++) {
//		for(int j=1; j<=i; j++) {
//			if(dp[i].second>=1) dp[i].first=dp[i-1].first&a[i],dp[i].second--;
//			else dp[i].first=max(dp[i-1].first,dp[i-j].first&a[i]);
//		}
//	}
//	cout<<dp[n].first<<endl;
//	fclose(stdin);
//	fclose(stdout);
//	return 0;
//}
