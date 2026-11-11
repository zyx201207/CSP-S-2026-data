#include<bits/stdc++.h>
using namespace std;
//priority_queue<int>
#define mian main
#define ll long long
int n;
ll a[500005],b[500005];
ll m;
int mian(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);    cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n;i ++){
		cin >> a[i];
	}
	sort (a,a + n);
	for (int i = 1;i < n;i ++){
		b[i] = a[i] - a[i - 1] + b[i - 1];
	}
	ll ans = -1,num = 1,sum = 0;
	int l = 0,r = 0;
	while (r < n - 1){
		if (l == r && sum > m){
			r = r + 1;
			l = r;
			num = sum = 0;
//			cout << "fsdgdfgf";
		}
	    r ++;
		sum += (r - l) * (b[r] - b[r - 1]);
		num ++;
		while(sum > m && l < r){
			sum -= b[r] - b[l];
			num --;
			l ++;
		}
		ans = max(ans,num);
//		cout << sum <<' '<< num <<endl;
	}
	cout << ans;
	return 0;
}
//5 8
//-3 -1 2 2 7
