#include <bits/stdc++.h>
using namespace std;
long long a[200010];
bool cmd(long long x,long long y){
	return x > y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ma = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmd);
	ma = a[1];
	long long aa = 1;
	while(aa <= ma){
		aa *= 2;
	}
	long long j = 1;
	long long ans = 0;
	while(aa >= 1){
		sort(a + 1,a + n + 1,cmd);
		aa /= 2;
		j = 1;
		while(a[j] >= aa){
			j ++;
			a[j-1] -= aa;
		}
		j --;
		if(j < m){
			continue;
		}else{
			ans += aa;
			n = j;
		}
	}
	cout << ans;
	return 0;
}
