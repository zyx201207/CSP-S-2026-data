#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, a[N];
int ans;
char c[N];
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i ++){
    	cin >> a[i] >> c[i];
	}
	int l = 1, r = n;
	int le1 = a[l], le2 = a[r];
	char c1 = c[l], c2 = c[r];
	while(l < r){
		if(c1 == c2){
			if(le1 > le2){
				le1 -= le2;
				r --;
				le2 = a[r];
				c2 = c[r];
			}else if(le1 < le2){
				le2 -= le1;
				l ++;
				le1 = a[l];
				c1 = c[l];
			}else{
				l ++;
				r --;
				le1 = a[l], le2 = a[r];
				c1 = c[l], c2 = c[r];
			}
		}else{
			if(le1 > le2){
				le1 -= le2;
				ans += le2;
				r --;
				le2 = a[r];
				c2 = c[r];
			}else if(le1 < le2){
				le2 -= le1;
				ans += le1;
				l ++;
				le1 = a[l];
				c1 = c[l];
			}else{
				ans += le1;
				l ++;
				r --;
				le1 = a[l], le2 = a[r];
				c1 = c[l], c2 = c[r];
			}
		}
		
	}
	cout << ans;
    return 0;
}
//2026 csp-j/s rp ++;
