#include<bits/stdc++.h>
//Oct31==Dec25?
#define int long long

using namespace std;

const int N = 5e5+ 86;

int n, m;

int a[N];

int d = 1;//¹«²î 

struct egde{
	int gc, he;
}b[N];

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	
	}
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; ++i){
		if(n >= 2 && (a[2] - a[1]) == (a[i] - a[i-1])){
			d++;
		}
	}
	if(a[n] == a[1]){
		cout << n;
	}else if( d == n){
		int cha = (a[2] - a[1]);
		int shu = m / cha;
		int ans = 1;
		for(int i = 1; i <= n; ++i){
			if(shu - i >= 0){
				shu -= i; 
				ans += 1;
				
			}else{
				break;
			}
			
		}
		
		if(ans >= n){
			cout << n;
		}else{
			cout << ans;
		}
	}else{
		int ans = 0;
		b[1].he = 0;
		for(int i = 2; i <= n; ++i){
			b[i - 1].gc = a[i] - a[i-1];
			b[i].he = b[i-1].gc + b[i-1].he;
			
		}
		for(int i = n; i >= 1; --i){
			for(int j = 1; j <= i; ++j){
				if(m >= b[i].he - b[j].he){
					ans = max(ans, i - j + 1);
				}
			}
		}
		cout << ans;
	}
	return 0;
}
/*5 5
1 2 4 8 9*/

