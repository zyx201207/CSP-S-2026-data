#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int n, ans = 1;
ll m, a[600000], s[600000];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	int l, r, mid;
	for(int i = 2; i <= n; i++){
		l = 1;
		r = i;
		while(l <= r){
			mid = (l + r) / 2;
			if((i - mid) * a[i] - (s[i - 1] - s[mid - 1]) <= m){
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		//cout << i << ' ' << l << endl;
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	
	return 0;
}

//X X XXX
//now 14:49, end of t1
//ohhh t1 so ez
//but if i cant get 100 in t2
//i may afo ):
