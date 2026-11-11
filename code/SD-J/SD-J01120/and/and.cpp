#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+10;
int n,ans,m,a[N];
int st[N];
void dfs(int u){
	if(u==n+1){
		int s=0,sum;
		for(int i=1;i<=n;i++){
			if(st[i]==1){
				sum=a[i];
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(st[i]==1){
				sum&=a[i];
				s++;
			}
		}
		if(s==m) ans=max(ans,sum);
		return;
	}
	st[u]=1;
	dfs(u+1);
	st[u]=0;
	dfs(u+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n<=25) dfs(1);
	else{
		sort(a+1,a+n+1);
		ans=a[n-m+1];
		for(int i=n-m+1;i<=n;i++){
			ans&=a[i];
		}
	}
	cout << ans;
	return 0;
}

