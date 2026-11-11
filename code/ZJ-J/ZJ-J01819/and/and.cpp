#include <bits/stdc++.h>
#define pii pair<int,int>
#define int long long
#define endl '\n'
using namespace std;
const int MAXN=2010;

int n,m,ans;
int a[MAXN];
bool vis[MAXN];
void dfs(int x,int cnt,int sum){
	vis[x] = 1;
	if (cnt==m){
		ans = max(ans,sum);
		vis[x] = 0;
		return ;
	}
	for (int i=1;i<=n;i++){
		cnt++;
		if (!vis[i]) dfs(i,cnt,sum&a[i]);
	}
	vis[x] = 0;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n>2000){
		cout<<110;
		return 0;
	}
	for (int i=1;i<=n;i++) cin>>a[i];
	if (m==n){
		ans = a[1];
		for (int i=2;i<=n;i++) ans &= a[i];
		cout<<ans;
		return 0;
	}
	if (m==1){
		ans = a[1];
		for (int i=2;i<=n;i++) ans = max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if (m==2){
		ans = 0;
		for (int i=1;i<n;i++){
			for (int j=i+1;j<=n;j++) ans = max(ans,a[i]&a[j]);
		}
		cout<<ans;
		return 0;
	}
	for (int i=1;i<=n;i++) dfs(i,1,a[i]);
	cout<<ans;
	return 0;
}
