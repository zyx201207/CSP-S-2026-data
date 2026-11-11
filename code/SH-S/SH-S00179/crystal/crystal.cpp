#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long pre[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		pre[i] = pre[i - 1] + a[i]; 
	} 
	long long ans = 1;
	for(int i = 2;i <= n;i++){
		long long targ = a[i];
		long long l = 1,r = i - 1;
		while(l < r){
			int mid = (l + r) / 2;
			if((i - mid) * targ - (pre[i - 1] - pre[mid - 1]) <= m) r = mid;
			else l = mid + 1;
		}
		ans = max(ans,i - l + 1);
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
