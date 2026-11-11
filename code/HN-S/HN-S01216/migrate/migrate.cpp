#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e6 + 10;

int n, d;
int a[N];

int fd1(int x, int st){
	int l = st + 1, r = n;
	int ans = st;
	
	while(l <= r){
		int mid = (l + r) >> 1;
		
//		cout << "fd1 : " << mid << ' ' << a[mid] << ' ' << x << '\n';
		
		if(a[mid] <= x){
			ans = max(ans, mid);
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	
	return ans;
}

int fd2(int x, int st){
	int l = st + 1, r = n;
	int ans = n + 1;
	
	while(l <= r){
		int mid = (l + r) >> 1;
		
//		cout << "fd2 : " << mid << ' ' << a[mid] << ' ' << x << '\n';
		
		if(a[mid] > x){
			ans = min(ans, mid);
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	
	return ans;
}

void solve(int C){
	cin >> n >> d;
	
	if(n <= 3){
		cout << 0 << '\n';
		return;
	}
	
	if(C >= 11 && C <= 12){
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		
		int cz = a[2] - a[1];
		
		if(2 * cz > d || 3 * cz <= d){
			cout << 0 << '\n';
			return;
		}
		
		int ans = 0;
		
		for(int l=1;l<=n - 3;l++){
			int r = l + 3;
			
			int ls = ((l - 1) >> 1) + 1;
			int rs = ((n - r) >> 1) + 1;
			
			ans += ls * rs;
		}
		
		cout << ans << '\n';
	}
	else{
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		
		int ans = 0;
		
		for(int i=1;i<=n - 3;i++){
			int zz = fd1(a[i] + d, i);
			
	//		cout << "zz : " << i << "->" << zz << '\n';
			
			if((zz - i) >= 2){
	//			cout << "kn : ";
				int lb = fd2(a[zz - 2] + d, zz);
				int rb = fd1(a[zz - 1] + d, zz);
	//			cout << a[zz - 1] + d << ' ' << zz + 1 << ' ' << a[zz - 2] + d << ' ' << zz + 1 << '\n';
	//			cout << lb << ' ' << rb << '\n';
				
				if(lb <= rb){
					ans += rb - lb + 1;
				}
			}
		}
		cout << ans << '\n';
	}
	
	
	
}

signed main(){
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int C, T;
	cin >> C >> T;
	
	while(T--){
		solve(C);
	}
	
	return 0;	
} 
