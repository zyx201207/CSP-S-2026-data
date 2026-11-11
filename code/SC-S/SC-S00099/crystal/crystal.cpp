#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	} 
	sort(a+1,a+1+n);
	long long ans = 1;
	long long re = 0;
	long long t = 0;
	for(int i = 2; i <= n; i++){
		long long sum = 0;
		long long tmp = 1;
		for(int j = 1; j < i; j++){
			if(sum + a[i]-a[j] > m) break;
			sum += a[i] - a[j];
			tmp++;
		}
		if(tmp > ans) ans = tmp, re = sum, t = a[i];
	}
	while(n - re){
		if(re + ans >= n) break;
		re += ans;
		t++;
		for(int i = 1; i <= n; i++){
			if(a[i] == t) ans++;
		}
	}
	//ans = max(ans,tmp);
	//cout << t << endl;
	cout << ans;
	return 0;
}