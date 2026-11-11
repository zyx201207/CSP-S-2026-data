#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a[300000],l,r;
	char c[300000];
	long long ans = 0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	l=1;
	r=n;
	while (r>l){
		if (c[l]==c[r]){
			if (a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if (a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			if (a[l]>a[r]){
				ans += a[r];
				a[l]-=a[r];
				r--;
			}
			else if (a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else{
				ans+=a[l];
				l++;
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}
