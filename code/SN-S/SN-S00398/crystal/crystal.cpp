#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int num = 0;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		num = 0;
		for(int j = i;j <= n;j++){
			num += a[j];
			if(num + n == j * a[j + 1]){
				ans = j + 1;
			}
		}
	}
	cout << ans;
	return 0;
}
