#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
//	vector<int> ls = {1, 2, 3, 5};
//	cout << (lower_bound(ls.begin(), ls.end(), 3)-ls.begin());
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, char> > a(n+1);
	char s;
	vector<int> sum(n+1, 0);
	int len = 0;
	bool pd = true;
	for(int i = 1;i <= n;i++){
		cin >> a[i].first >> a[i].second;
		if(i != 2){
			if(a[i].second != s){
				pd = false;
			}
		}
		sum[i] = sum[i-1]+a[i].first;
		len += a[i].first;
		s = a[i].second;
	}
	if(pd){
		cout << 0;
	}
	else{
		int ans = 0, last = 0;
		for(int i = 1;sum[i] <= len/2;i++){
			last = i;
			int l = len-sum[i-1], r = len+1-sum[i];
			swap(l, r);
			int nodel = lower_bound(sum.begin(), sum.end(), l)-sum.begin(), noder = lower_bound(sum.begin(), sum.end(), r)-sum.begin();
			if(nodel == noder){
				if(a[nodel].second != a[i].second){
					ans += r-l+1;
				}
				continue;
			}
			//nodel
			if(a[nodel].second != a[i].second){
				ans += sum[nodel]-l+1;
			}
			//noder
			if(a[noder].second != a[i].second){
				ans += r-sum[noder-1];
			}
			for(int j = nodel+1;j <= noder-1;j++){
				if(a[j].second != a[i].second){
					ans += a[j].first;
				}
			}
		}
		if(sum[last] < len/2){
			int l = len-sum[last], r = len+1-len/2;
			swap(l, r);
			int nodel = lower_bound(sum.begin(), sum.end(), l)-sum.begin(), noder = lower_bound(sum.begin(), sum.end(), r)-sum.begin();
//			cout << noder << "****\n" << nodel << "*****\n";
			if(nodel == noder){
				if(a[nodel].second != a[last+1].second){
					ans += r-l+1;
				}
			}
			else{
				//nodel
				if(a[nodel].second != a[last+1].second){
					ans += sum[nodel]-l+1;
				}
				//noder
				if(a[noder].second != a[last+1].second){
					ans += r-sum[noder-1];
				}
				for(int j = nodel+1;j <= noder-1;j++){
					if(a[j].second != a[last+1].second){
						ans += a[j].first;
					}
				}
			}
		}
		cout << ans;
	}
	return 0;
}
/*
3
1000000000 a
1 b
1 c

2

3
2 a
2 b
3 c

3

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3000000000

3
2 a
3 b
1 c

2

5
2 a
1 d
1 c
1 b
1 c

3

3
2 a
2 b
2 c

2

3
2 a
1 b
2 a

0

5
2 a
2 b
3 c
2 a
2 a

2
*/