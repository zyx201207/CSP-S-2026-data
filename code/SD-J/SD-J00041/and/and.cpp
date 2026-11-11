#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+7;
int n,m,a[maxn],vis[maxn],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)cin >> a[i];
	for(int i = 30;i>=0;i--){
		int cnt = 0;
		for(int j = 1;j<=n;j++){
			if(!vis[j] && ((a[j]>>i)&1))cnt++;
		}
		if(cnt>=m){
			ans+=(1<<i);
			for(int j = 1;j<=n;j++){
				if(!vis[j] && ((a[j]>>i)&1))vis[j]=0;
				else vis[j]=1;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}

