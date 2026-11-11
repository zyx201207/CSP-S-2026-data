#include<bits/stdc++.h>
using namespace std;
long long n,t,l,r,cnt;
struct rpjj{
	long long k;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++){
		cin >> a[i].k >> a[i].c;
	}
	if(n == 1){
		cout << 0;
		return 0;
	}
	t = n;
	l = 1;
	r = n;
	while(t > 1){
		long long p = a[l].k;
		while(p >= a[r].k){
			if(a[r].c != a[l].c) cnt += a[r].k;
			p -= a[r].k;
			r--;
			t--;
		}
		if(p == 0){
			l++;
		}else{
			a[r].k -= p;
			if(a[l].c != a[r].c) cnt += p;
			l++;
		}
		t--;
	}
	cout << cnt;
	return 0;
}
