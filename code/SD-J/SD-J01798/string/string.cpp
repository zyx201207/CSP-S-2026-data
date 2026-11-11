#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n;
ll a[N], sum[N], L, ans;
char c[N]; 
int main() { 
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i ++) {
    	char C;
    	cin >> a[i] >> c[i]; 
    	sum[i] = sum[i - 1] + a[i]; 
	}  
	L = sum[n]; 
	for(int i = 1;i <= n;i ++) {
		if(sum[i] >= L / 2) {
			ll h1 = L / 2 - sum[i - 1]; 
			ll h2 = a[i] - h1; 
			if(L % 2 == 1) h2 --;
			int p1, p2;
			p1 = p2 = i;
			while(p1 > 0 && p2 < n + 1) {
				if(c[p1] != c[p2]) ans += min(h1, h2); 
				if(h1 > h2) { 
					h1 -= h2;
					p2 ++;
					h2 = a[p2];
				}
				else if(h1 == h2) { 
					p1 --;
					p2 ++;
					h1 = a[p1];
					h2 = a[p2];
				}
				else if(h2 > h1) { 
				    h2 -= h1;
					p1 --;
				    h1 = a[p1];
				}
			}  
			break;
		}
	}
	cout << min(ans, L - ans);
	return 0;
}

