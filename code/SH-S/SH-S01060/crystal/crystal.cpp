#include <bits/stdc++.h>
using namespace std;
long long n, m, ml = 0, l, r, cnt = 1;
long long a[500010];
long long s[500010];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(long long i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	s[0] = 0x3f3f3f3f;
//	cout << 0 << endl;
	for(long long i=1; i<=n; i++) {
		for(long long j=1; j<=n; j++) {
			s[i] += abs(a[i] - a[j]);
		}
		if(s[i]<s[ml]) ml = i;
//		cout << s[i] << " ";///
	}
//	cout << endl;///
	l = ml - 1, r = ml+1;
//	cout<< ml << " " << l << " " << r << " " <<endl;///
	while(m>0&&l!=0&&r!=n+1) {
//		cout << endl << cnt;///
//		cout<<endl<< ml << " " << l << " " << r << " " <<endl;///
//		printf("%d", ml);//
		if(a[ml] - a[l] > cnt * (a[r] - a[ml])) {
//			cout << 1 << endl;///
//			printf("%d %d %d %d %d %d %d\n", a[ml] - a[l], cnt * (a[r] - a[ml]), a[ml], a[l], a[r], cnt, ml);///
//			cout << ml << endl;//
			cnt++;
			for(long long i=ml+1; i<=r; i++) {
				m-=a[r] - a[i];
				a[i] = a[r];
			}
			r++;
		} else if(a[l] == a[r]) {
//			cout << 2 << endl;///
			l--;
			r++;
			cnt+=2;
		} else {
//			cout << 3 << endl;///
			m-=a[ml] - a[l];
			a[l] = a[ml];
//			cout << a[ml] - a[l] << a[ml] << a[l] << ml << l <<endl;//
			l--;
			cnt++;
		}
//		for(int i=1;i<=n;i++){///
//			cout << a[i] << " ";///
//		}///
//		cout << endl << m << endl;///
//		cout << endl << cnt;//
	}
	if(m==0) cnt ++;
	cout << cnt-1;
	return 0;
}
