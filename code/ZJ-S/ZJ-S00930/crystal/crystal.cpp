#include<bits/stdc++.h>
using namespace std;
#define For(i, j, k) for(int i = j; i <= k; i++)
#define MaxN 500005
#define INF 100000000000000
#define int long long

int n, m, ans;
int a[MaxN];
int d[MaxN], s[MaxN];

int sum(int l, int r){
	if(l == r) return d[l];
	return s[r] - s[l-1];
}

//bool check(int ind, int k){		//from ind-k+1 to ind
//	return sum(ind-k+1, ind) <= m;
//}

int f[MaxN];

bool check(int k){
	if(k == 1) return true;
//	memset(f, 0, sizeof(f));
	//f[k] = (k-1)d[k] + (k-2)d[k-1] + ... 1*d[1]
	f[k] = 0;
	For(i, 2, k){
		f[k] += (i-1) * d[i];
	}
	if(f[k] <= m) return true;
	For(i, k+1, n){
		//i-k+1 ~ i
		f[i] = f[i-1] + (k-1) * d[i] - sum(i-k+1, i-1);
		if(f[i] <= m) return true;
	}
	return false;
//	cout << "k = " << k << ", f[] = ";
//	int flag = false;
//	For(i, k, n){
//		cout << f[i] << ' ';
//		if(f[i] <= m){
//			flag = true;
//		}
//	}
//	cout << endl;
//	return flag;
}

signed main()
{
//	freopen("data.in", "r", stdin);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	For(i, 1, n){
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	For(i, 1, n){
		d[i] = a[i] - a[i-1];
		s[i] = d[i] + s[i-1];
//		cout << d[i] << ' ';
	}
//	cout << endl;
//	For(i, 1, n){
//		cout << s[i] << ' ';
//	} cout << endl;
	int l = 1, r = n;
	while(l <= r){
		int mid = (l+r) / 2;
		if(check(mid)){
			ans = max(ans, mid);
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << ans << endl;

    return 0;
}
