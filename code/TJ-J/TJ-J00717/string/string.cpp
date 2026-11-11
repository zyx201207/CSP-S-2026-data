#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long a[200010];
	char s[200010], mid_c;
	int n, mid;
	long long num=0;
	
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i] >> s[i];
		num += a[i];
	}
	if (num%2 == 1){
		mid = (num+1)/2;
		int i;
		for (i=1; i<=n; i++){
			if (mid > a[i]) mid -= a[i];
			else if (mid <= a[i]){
				mid_c = s[i];	
				break;
			} 
		}
		
		long long ans = 0;
		int h = 1;
		for(int j = n; j>i; j--, h++){
			if (a[j] == a[h] && s[j] == s[h]){
				ans += 0;
			}
			else if (a[j] == a[h]){
				ans += a[j];
			}
			else if (a[j] < a[h]){
				ans += a[j];
				a[h] -= a[j];
				h--;
			}
			else if (a[j] > a[h]){
				ans += a[h];
				h++;
				a[j] -= a[h]; 
				while (a[j]>a[h]){
					if (s[h] == s[j]) a[j] -= a[h];
					else {
						ans += a[h];
						a[j] -= a[h];
					}
					h++;
				}
				if (a[j] == a[h]){
					if (s[h] == s[j]){
						;
					}
					else ans += a[h];
				}
				else{
					if (s[h] == s[j]) a[h] -= a[j];
					else{
						ans += a[j];
						a[h] -= a[j];
						h--;
					}
				}
			}	
		}
		long long ansb = 0;
		int e = n;
		for(int j = 1; j<i; j++, e--){
			if (a[j] == a[e] && s[j] == s[e]){
				ansb += 0;
			}
			else if (a[j] == a[e]){
				ansb += a[e];
			}
			else if (a[j] < a[e]){
				ansb += a[j];
				a[e] -= a[j];
				e++;
			}
			else if (a[j] > a[e]){
				ansb += a[e];
				e--;
				a[j] -= a[e]; 
				while (a[j]>a[e]){
					if (s[e] == s[j]) a[j] -= a[e];
					else {
						ansb += a[e];
						a[j] -= a[e];
					}
					e--;
				}
				if (a[j] == a[e]){
					if (s[e] == s[j]){
						;
					}
					else ansb += a[e];
				}
				else{
					if (s[e] == s[j]) a[e] -= a[j];
					else{
						ansb += a[j];
						a[e] -= a[j];
						e++;
					}
				}
			}	
		}
		cout << min(ans, ansb);
				
	}
	else{
		mid = num/2;
		int i;
		for (i=1; i<=n; i++){
			if (mid > a[i]) mid -= a[i];
			else if (mid <= a[i]){
				mid_c = s[i];
				break;	
			} 
		}
		
		long long ans = 0;
		int h = 1;
		
		for(int j = n; j>=i+1; j--, h++){
			if (a[j] == a[h] && s[j] == s[h]){
				ans += 0;
			}
			else if (a[j] == a[h]){
				ans += a[j];
			}
			else if (a[j] < a[h]){
				ans += a[j];
				a[h] -= a[j];
				h--;
			}
			else if (a[j] > a[h]){
				ans += a[h];
				h++;
				a[j] -= a[h]; 
				while (a[j]>a[h]){
					if (s[h] == s[j]) a[j] -= a[h];
					else {
						ans += a[h];
						a[j] -= a[h];
					}
					h++;
				}
				if (a[j] == a[h]){
					if (s[h] == s[j]){
						;
					}
					else ans += a[h];
				}
				else{
					if (s[h] == s[j]) a[h] -= a[j];
					else{
						ans += a[j];
						a[h] -= a[j];
						h--;
					}
				}
			}	
		}
		cout << ans;
		
	}
	
	
	return 0;
}
