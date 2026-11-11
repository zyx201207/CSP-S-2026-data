#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n,a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i] >> c[i];
	int l = 1,r = n,cnt = 0;
	while (l != r){
		if (c[l] == c[r]){
			if (a[l] < a[r]){
				a[r] -= a[l];
				l++;
			}else if (a[l] > a[r]){
				a[l] -= a[r];
				r--;
			}else{
				l++;
				r--;
			}
		}
        else{
			if (a[l] < a[r]){
				a[r] -= a[l];
				cnt += a[l];
				l++;
			}else if (a[l] > a[r]){
				a[l] -= a[r];
				cnt += a[r];
				r--;
			}else{
				cnt += a[l];
				if (r - l > 1){
					l++;
					r--;
				}else{
					break;
				}
			}
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
