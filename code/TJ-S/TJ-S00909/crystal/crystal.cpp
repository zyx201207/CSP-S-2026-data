#include<bits./stdc++.h>
using namespace std;

const long long N = 500005;
long long int a[N];
long long n,m;

bool cmp(long long x,long long y){
	return x > y;
}

void solve1(){
	sort(a+1,a+1+n,cmp);
	long long ans = -1;
	for(long long i = 1; i <= n; i ++){
		long long sum = 0;
		long long cnt = 1;
		for(long long j = i + 1; j <= n + 1; j ++){
			sum += (a[i] - a[j]);
			if(sum > m) {
				ans = max(ans,cnt);
				break;
			}
			cnt++;
	  }
	}
	cout << ans;
}

void solve2(){
	int cnt = abs(a[2] - a[1]);
	long long j = 0;
	for(; m >= 0; j ++){
		m = m - cnt * (j + 1);
	}
	cout << j;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}

	if(n <= 5000) solve1();
	else solve2();
	
	return 0;
}
