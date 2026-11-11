#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[1000005],a[1000005],nmax = -2e9,r,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int m,n;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		int x;
		cin >> x;
		cnt[x] ++;
		a[i] = x;
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= 1000000;i ++){
		if(cnt[i] > 1){
			r = i;
		}
		
	}
	if(r == 0){
		ans = a[n];
		for(int i = n - 1;i >= m;i --){
			ans = ans % a[i];
		}cout << ans;
	}else{
		ans = r;
	}
	cout << ans;	
	return 0;
}
