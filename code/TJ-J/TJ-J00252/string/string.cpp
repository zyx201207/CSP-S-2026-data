#include<bits/stdc++.h>
using namespace std;
#define int long long
long long n, L, ans;
struct node{
	int l;
	int r;
	int num;
}a[200005];
signed main(){
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		char y;
		cin >> x >> y;
		a[i].num = y - 'a' + 1;
		a[i].l = a[i - 1].r + 1;
		a[i].r = a[i - 1].r + x;
		L += x;
	}
	if(L % 2 == 1){
		for(int i = 1; i <= n; i++){
			if(L / 2 + 1 >= a[i].l && L / 2 + 1 <= a[i].r){
				int lll = (L / 2 + 1) - a[i].l;
				int rrr = a[i].r - (L / 2 + 1);
				if(lll < rrr){
					a[i].l += lll + lll + 1;
				}
				else{
					a[i].r -= rrr - rrr - 1;
				}
			}
		}
	}
	else{
		int f = 0;
		for(int i = 1; i <= n; i++){
			if(L / 2 > a[i].l && L / 2 < a[i].r){
				f = 1;
				int lll = (L / 2) - a[i].l;
				int rrr = a[i].r - (L / 2 + 1);
				if(lll < rrr){
					a[i].l += lll + lll + 1;
				}
				else{
					a[i].r -= rrr - rrr - 1;
				}
			}
		}
		if(f == 0){
			for(int i = 1; i <= n; i++){
				if(L / 2 == a[i - 1].r && L / 2 == a[i].l){
					if(a[i - 1].num != a[i].num){
						ans++;
						a[i - 1].r--;
						a[i].l++;
					}
				}
			}
		}	
	}
	int ll = 1, rr = n;
	while(ll < rr){
		if(a[ll].num != a[rr].num){
			if(a[ll].r - a[ll].l + 1 > a[rr].r - a[rr].l + 1){
				ans += a[rr].r - a[rr].l + 1;
				rr--;
				a[ll].l += a[rr].r - a[rr].l + 1;
			}
			else if(a[ll].r - a[ll].l + 1 == a[rr].r - a[rr].l + 1){
				ans += a[rr].r - a[rr].l + 1;
				ll++;
				rr--;
			}
			else{
				ans += a[ll].r - a[ll].l + 1;
				ll++;
				a[rr].r -= a[ll].r - a[ll].l + 1;
			}
		}
		else{
			if(a[ll].r - a[ll].l + 1 > a[rr].r - a[rr].l + 1){
				rr--;
				a[ll].l += a[rr].r - a[rr].l + 1;
			}
			else if(a[ll].r - a[ll].l + 1 == a[rr].r - a[rr].l + 1){
				ll++;
				rr--;
			}
			else{
				ll++;
				a[rr].r -= a[ll].r - a[ll].l + 1;
			}
		}
	}
	cout << min(ans, L / 2);
	
	
	return 0;
} 
