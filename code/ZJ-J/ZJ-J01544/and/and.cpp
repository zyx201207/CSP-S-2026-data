#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LOG = 30;

int n,k;
int a[N];
bool vis[N];
int ans = 0;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	memset(vis,false,sizeof vis);	
	
	for(int i=LOG;i>=0;i--){
		int cnt = 0;
		for(int j=1;j<=n;j++){
			if(vis[j]) continue;
			
			if((a[j] >> i) & 1) cnt++;
		}
		
		if(cnt >= k){
			ans += (1ll << i);
			for(int j=1;j<=n;j++){
				if(((a[j] >> i) & 1) == 0) vis[j] = true;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
