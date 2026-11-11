#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
struct node{
	ll l,r;
	char c;
}a[N];
int n; 
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	ll l = 0;
	for(int i = 1;i <= n;i ++){
		ll s;
		char c;
		cin >> s >> c;
		a[i].l = l + 1;
		a[i].r = l + s;
		a[i].c = c;
		l += s;
	}
//	cout << l << endl;
	int j = n;
	for(int i = 1;i <= j;i ++){
		ll l = a[i].l,r = a[i].r;
		while(l <= r){
			ll lr = a[j].l,rr = a[j].r;
			if(a[i].c == a[j].c){
				ll suml = r - l + 1;
				ll sumr = rr - lr + 1;
				if(suml > sumr)l += sumr,j--;
				else {
					if(sumr == suml){
						j --;
						break;
					} 
					a[j].r -= suml;
					break;
				}
			}else {
				ll suml = r - l + 1;
				ll sumr = rr - lr + 1;
				if(suml > sumr){
					l += sumr;
					j --;
					ans += sumr; 
				}else {
					if(sumr == suml){
						ans += sumr;
						j --;break;
					}
					a[j].r -= suml;
					ans += suml;
					break;
				}
			}
		}
	} 
	cout << ans;
	return 0;
} 
