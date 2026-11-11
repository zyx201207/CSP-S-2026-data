#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
int n,a[N];
ll m,mid,ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		m += a[i];
	}
	int k1 = 1,k2 = n;
	mid = m / 2;
	while(mid > 0){
		if(c[k1] == c[k2]){
			int k = min(a[k1],a[k2]);
			if(k == a[k1] && k == a[k2]){
				k1++,k2--;
			}else if(k < a[k1]){
				a[k1] -= k;
				k2--;
			}else{
				a[k2] -= k;
				k1++;
			}
			mid -= k;
		}else{
			int k = min(a[k1],a[k2]);
			if(k == a[k1] && k == a[k2]){
				k1++,k2--;
			}else if(a[k1] > k){
				a[k1] -= k;
				k2--;
			}else{
				a[k2] -= k;
				k1++;
			}
			ans += k;
			mid -= k;
		}
	}
	cout << ans;
	return 0;
}