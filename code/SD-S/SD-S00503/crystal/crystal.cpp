#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
const int N = 5e5 + 10;
long long a[N],sum[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i ++){
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 1;
	for (int i = 1;i <= n;i ++){
		int l = 1,r = i;
	//	cout <<"i : "<< i << endl;
		while(l <= r){
			int mid = (l + r) >> 1;
			
			int len = (i - mid + 1);
			long long qwq = len * 1ll * a[i] - (sum[i] - sum[mid - 1]);
		//	cout << mid << " " << len << " " << qwq << endl;
			if(qwq <= m){
				r = mid - 1;
				ans = max(ans,len);
			}else{
				l = mid + 1;
			}
		}
	}
	cout << ans;
	return 0;
}
