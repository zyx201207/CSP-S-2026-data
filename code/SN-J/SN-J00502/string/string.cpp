#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ull N = 2e5+10;
ull n;
ull len = 0;
ull a;
char c[N];
ull start[N];                                 // start[i]表示第i段的开始位置 
ull last[N];                                   // last[i]表示第i段的结束位置
char rc[N];
ull rstart[N];
ull rlast[N];
ull index=0, rindex=0;
ull i=0, lasti = 0;
ull ans = 0;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(ull i=1;i<=n;i++){
		cin >> a >> c[i];
		len += a;
		last[i] = last[i-1] + a;
		start[i] = last[i] - a + 1;
	}
	for(ull i=1;i<=n;i++){
		rstart[i] = len-last[n-i+1]+1;
		rlast[i] = len-start[n-i+1]+1;
		rc[i] = c[n-i+1];
	}
//	cout << "\n";
//	for(ull i=1;i<=n;i++){
//		cout << start[i] << " " << last[i] << " " << c[i] << "\n";
//	}
//	cout <<"\n";
//	for(ull i=1;i<=n;i++){
//		cout << rstart[i] << " " << rlast[i] << " " << rc[i] << "\n"; 
//	}
//	cout << "\n";
	for(;index<=n && rindex<=n;){
		i = min(last[index], rlast[rindex]);
		ans += (c[index] != rc[rindex]) * (i-lasti);
		lasti = i;
		if(last[index] < rlast[rindex]) index++;
		else rindex++;
	}
	cout << ans/2 <<"\n";
	return 0;
}
