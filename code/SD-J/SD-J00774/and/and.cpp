#include <bits/stdc++.h>
using namespace std;
int a[200005];
int s[200005][100];
vector <int> c[35];
queue<int>q[200005];
string b;
int n,m;
int cntm=0;
int cnt=0;
int v[200005];
void solve() {
	for(int i=1; i<=n; i++) {

	}
	for(int i=1; i<=n; i++) {
		for(int j=cntm; j>=1; j--) {
			if(s[i][j]==1) {
				c[j].push_back(i);
				q[i].push(j);
//				cout << j << " ";
			}
		}
//		cout << endl;
	}
	int t=0;
	for(int i=cntm; i>=1; i--) {
		if(c[i].size()>=m) {
			t=i;
			break;
		}
	}
	for(int i=cntm; i>t; i--) {
		for(int j:c[i]) {
//			cout << j << " ";
			if(q[j].front()==i) {
				q[j].pop();
			}
		}
//		cout << endl;
	}
	int summ=0;
	for(int i=t; i>=1; i--) {
		summ=0;
		for(auto j:c[t]) {
			if(q[j].front()==i) {
				summ++;
				q[j].pop();
			}
		}
//		cout << summ << endl;
		if(summ>=m) {
			b+='1';
		} else {
			b+='0';
		}
	}
//	cout << t << " ";
//	cout << b << "\n";
	int suma=0;
	for(int i=0; i<t; i++) {
		suma+=pow(2,t-i-1)*(b[i]-'0');
	}
	cout << suma;
}
void s2() {
	if(m==1) {
		sort(a+1,a+n+1);
		cout << a[n];
	} else {
		if(m==n) {
			int cnt=a[1];
			for(int i=2; i<=n; i++) {
				cnt&=a[i];
			}
			cout << cnt;
		} else {
			if(m==2) {
				int maxx=-1;
				for(int i=1; i<=n; i++) {
					for(int j=1; j<=n; j++) {
						if(i==j) {
							continue;
						}
						maxx=max(maxx,a[i]&a[j]);
					}
				}
				cout << maxx;
			}
		}
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int sums=0;
	for(int i=1; i<=n; i++) {
		cnt=0;
		cin >> a[i];
		v[a[i]]++;
		if(a[i]<4) {
			sums++;
		}
		int t=a[i];
		while(t) {
			s[i][++cnt]+=t%2;
			t/=2;
		}
		cntm=max(cntm,cnt);
	}
	if(sums==n) {
		if(v[3]>=m) {
			cout << 3;
			return 0;
		}
		if(v[2]>=m) {
			cout << 2;
			return 0;
		}
		if(v[2]+v[3]>=m) {
			cout << 2;
			return 0;
		}
		if(v[1]>=m) {
			cout << 1;
			return 0;
		}
		if(v[3]+v[1]>=m) {
			cout << 1;
			return 0;
		}
	}
	if(n>=2000) {
		solve();
		return 0;
	} else {
		if(n<=20) {
			solve();
			return 0;
		} else {
			s2();
		}
	}
	return 0;
}
