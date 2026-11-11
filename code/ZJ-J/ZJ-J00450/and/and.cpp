#include <bits/stdc++.h>
#define int long long
using namespace std;

bool a[200010][35];
bool vis[200010];

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		for(int j=30;j>=0;j--){
			if(x&(1<<j))a[i][j]=1;
		}
	}
	
	int ans=0;
	
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!vis[j] && a[j][i])cnt++;
		}
		if(cnt>=m){
			ans|=(1<<i);
			for(int j=1;j<=n;j++){
				if(!a[j][i])vis[j]=1;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
