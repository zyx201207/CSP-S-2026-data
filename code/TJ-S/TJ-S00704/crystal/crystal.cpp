#include<bits/stdc++.h> 
using namespace std;
long long int n, m, k;
long long int a[500010], b[500010], aaa[500010];
long long int c[500010], d[500010];
long long int ans = 1, ans2 = 1, ansx = 1, ansd = 1;
void s(long long int l, long long int r){
	long long int mid = (l + r) / 2;
	if(l < r){
		s(l, mid);
		s(mid + 1, r);
	}
	long long int i = l, j = mid + 1, cnt = 1;
	while(i <= mid && j <= r){
		if(d[i] <= d[j]){
			b[cnt++] = d[i++];
		}
		else{
			b[cnt++] = d[j++];
		}
	}
	while(i <= mid){
		b[cnt++] = d[i++];
	}
	while(j <= r){
		b[cnt++] = d[j++];
	}
	j = 1;
	for(i = l; i <= r; i++){
		d[i] = b[j++];
	}
	
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		d[i] = a[i];
	}
	s(1, n);
	aaa[n] = d[n];
	for(int i = 1; i <= n - 1; i++){
		aaa[i] = d[i];
		c[i] = d[i + 1] - d[i];
		d[i] = c[i];
	}
	s(1, n - 1);
	k = m;
	for(int i = 1; i <= n - 1; i++){
		k = k - (aaa[i + 1] - aaa[i]) * i;
		if(k < 0){
			break;
		}
		ansx++;
	}
	k = m;
	for(int i = n; i >= 2; i--){
		k -= (aaa[i] - aaa[i - 1]) * (n - i + 1);
		if(k < 0){
			break;
		}
		ansd++;
	}
	k = m;
	for(int i = 1; i <= n - 1; i++){
		k -= d[i] * i;
		if(k <= 0){
			break;
		}
		ans++;
	}
	ansd = max(ansd, ansx);
	ans = max(ans, ansd);
	printf("%lld", ans);
	return 0;
}
