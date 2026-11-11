#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;

const int N = 5e5 + 10;
int a[N];

bool check(int x) {
	int t = 0;
	for (int i = 1; a[i] <= x && i <= n; i++) {
		t += (x - a[i]);
	}

	return t <= m;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin>>n>>m;

	for (int i = 1; i <= n; i++) {
		cin>>a[i];
	}
	
	sort(a+1, a+n+1);
	
	int l=1, r=n+m;
	while(l < r){
		//cout<<l<<" "<<r<<endl;
		int mid = (l + r + 1) >> 1;
		if(check(mid)){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	
	int ans = 0;
	for(int i=1; a[i] <= l && i <= n; i++){
		ans ++;
	}
	
	cout<<ans<<endl;

	return 0;
}

/*

half split ans, I think. 14:38

??? there is sth wrong with ex. 4 ???
why is ans 315275
15:15

the teacher said he couldn't help
let's wait if it's actually wrong?
15:21

*/
