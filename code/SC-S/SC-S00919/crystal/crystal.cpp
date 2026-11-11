# include <bits/stdc++.h>
# define int long long
# define endl "\n"
using namespace std;

const int N = 5e5 + 10;

int n, m;
int a[N];

void solve_m0(){
	int ans = 0, cnt = 1;

	for(int i=2;i<=n;i++){
		if(a[i] == a[i-1]) cnt ++;
		else cnt = 1;
		ans = max(ans, cnt);
	}
	
	cout << ans << endl;
	return ;
}

//void solve_diff(int k){	
//	int sum = 0;
//	for(int i=1;i<=n-1;i++){
//		if(sum + k > m){
//			cout << (i-1)*k << endl;
//			return ;
//		}
//		sum += k;
//	}
//	
//	cout 
//	
//	return ;
//}

inline int getd(int x, int y){
	return abs(a[x] - a[y]);
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	bool f = true;

	cin >> n >> m;

	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	
	sort(a+1, a+n+1);
	
	int k = a[2] - a[1];

	for(int i=2;i<=n;i++){
		if(a[i] - a[i-1] != k){
			f = false;
			break;
		}
	}

	if(m == 0){
		solve_m0();
		return 0;
	}
//	else if(f){
//		solve_diff(k);
//		return 0;
//	}

	int ans = 0;
	for(int x=1;x<=n;x++){
		int sum = 0, cnt = 1;
		int i=x-1;

		sum = 0;		
		while(i >= 1){
			int di = getd(i, x);
			if(sum + di <= m){
				sum += di;
				i --;
				cnt ++;
			} else break;
		}
		
		ans = max(ans, cnt);
	}
	
	cout << ans << endl;

	return 0; 
}