/*
#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 5e5 + 10;

#define int long long

LL m,a[N],prefix[N];

signed main(){
	freopen("crystal4.in","r",stdin);
	//~ freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n; cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) prefix[i] = prefix[i - 1] + a[i];
	//~ for(int i = 1;i <= n;i++) cout << prefix[i] << " \n"[i == n];
	sort(a + 1,a + 1 + n);
	int res = 1;
	for(int i = 2;i <= n;i++){
		//~ cout << "turn " << i << ":\n";
		int l = 1,r = i - 1,tmp = i;
		while(l <= r){
			int mid = (l + r) >> 1;
			LL num = a[i] * (i - mid) - (prefix[i - 1] - prefix[mid - 1]);
			//~ cout << mid << " " << num << "\n";
			if(num <= m){
				tmp = mid;
				r = mid - 1;
			}else l = mid + 1;
		}
		//~ cout << tmp << "\n";
		res = max(i - tmp + 1,res);
	}
	//~ cout << "res:";
	cout << res << "\n";
	return 0;
}
*/
//~ /*
#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 5010;

#define int long long

LL m,a[N],diff[N][N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n; cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			diff[i][j] = a[i] - a[j];
		}
	}
	int res = 0;
	for(int i = 1;i <= n;i++){
		int tmp = i,sum = 0;
		for(int j = i;j >= 1;j--){
			sum += diff[i][j];
			if(sum > m){
				tmp = j + 1;
				break;
			}
		}
		res = max(res,i - tmp + 1);
	}
	cout << res << "\n";
	return 0;
}
//~ */
