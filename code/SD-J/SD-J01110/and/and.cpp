#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[200010],vis[200010],step[200010];
void dfs(int u,int cnt){
	if(u>n){
		if(cnt==m){
			int sum=2147483647;
			for(int i=1;i<=m;i++){
				sum=sum&step[i];
			}
			ans=max(ans,sum);
		}
		return ;
	}
	step[++cnt]=a[u];
	dfs(u+1,cnt);
	cnt--;
	dfs(u+1,cnt);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout << a[n] << "\n";
	}else if(m==n){
		ans=2147483647;
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout << ans << "\n";
	}else if(m==2){
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout << ans << "\n";
	}else{
		dfs(1,0);
		cout << ans << "\n";
	}
	return 0;
}
