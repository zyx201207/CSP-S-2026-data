#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 5e5 + 11;

int n,a[N],r,d[N],m,ans;
int now,sum[N];

signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	
	for(int i = 1;i <= n;i ++)
		cin >> a[i];
		
	sort(a + 1,a + n + 1);
	
	for(int i = 2;i <= n;i ++)
		d[i] = a[i] - a[i - 1];
		
	for(int i = 1;i <= n;i ++)
		sum[i] = sum[i - 1] + d[i];
		
	
		
	r = 1;
		
	for(int i = 1;i <= n;i ++){
		now -= sum[r] - sum[i - 1];
		if(r < i){
			r = i;
			now = 0;
		}
		while(r + 1 <= n && now + d[r + 1] * (r - i + 1) <= m){
			now += d[r + 1] * (r - i + 1);
			r ++;	
		}
		
//		cout << i << " " << r << "\n"; 
		
		ans = max(ans,r - i + 1);
	}
	
	cout << ans;
	
	return 0;
}
