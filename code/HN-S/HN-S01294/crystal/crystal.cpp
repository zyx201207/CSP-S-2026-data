#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
const long long inf = 1e18;
long long a[N], n, m;
long long max(long long a, long long b){return (a>b?a:b);}
long long min(long long a, long long b){return (a<b?a:b);}
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){cin >> a[i];}
	sort(a+1, a+n+1, cmp);
	int ans = 0;
	for(int i = 1;i <= n;i ++){
		if(a[i] == a[i-1])continue;
		int mm = m, cnt = 0;;
		for(int j = i;j <= n&&mm;j ++){
			if(mm < (a[i]-a[j])){break;}
			mm -= (a[i]-a [j]);
			cnt ++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
} 
