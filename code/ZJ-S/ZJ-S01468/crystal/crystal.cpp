#include<bits/stdc++.h>
#define int long long
#define I_am_free return
#define fast_cin cin.tie(0);
#define fast_cout cout.tie(0);
#define fast ios::sync_with_stdio(0);

using namespace std;

const int N = 500005;
int a[N] , n , m;

void gg() {
	
	fast_cin
	fast_cout
	fast
	
}

int maxn = 0;
int idmax , minn = 1e18;

signed main() {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	
	gg();

	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		
		cin >> a[i];
		idmax = max(idmax , a[i]);
		minn = min(minn , a[i]);
		
	}

	stable_sort(a+1 , a+1+n);

	if(n * n <= 25000000) {
		
		for(int i = 1; i <= n; i ++) {
			
			int x = m , cnt = 1;
			for(int j = i-1; j >= 1; j --) {
				
				if(a[i]-a[j] <= x) {
					
					x=x - (a[i] - a[j]);
					cnt ++;
					
				} else	break;
				
			}
			maxn = max(maxn , cnt);
			
		}
		cout << maxn;
		
	} else {
		if(n * (idmax - minn) <= m)	cout << n;
		else {
			
			int x = m,cnt = 1;
			for(int i = n-1; i >= 1; i --) {
				
				if(a[n] - a[i] <= x) {
					
					x = x - (a[n] - a[i]);
					cnt ++;
					
				}
				
			}
			cout << cnt;
			
		}
	}

	I_am_free 0;
}
