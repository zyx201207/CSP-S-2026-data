#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 2e5 + 100;
int a[N];
char b[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i] >> b[i];
	int l = 1,r = n;
	long long ans = 0;
	while(l < r){
		int mn = min(a[l],a[r]);
		if(b[l] != b[r]){
			ans += 1LL * mn;
		} 
		a[l] -= mn;
		a[r] -= mn;
		if(a[l] <= 0) l++;
		
		if(a[r] <= 0) r--;
	}
	cout << ans << endl;
	return 0;
}

