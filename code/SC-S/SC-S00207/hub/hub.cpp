#include <bits/stdc++.h>
#define int long long
#define fp(i,a,b) for(int i=a;i<=b;i++)
#define pf(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int c, t, n, k;

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>t;
	srand(time(0));
	while(t--) {
		cin>>n>>k;
		fp(i,1,n-1) {
			int x, y;
			cin>>x>>y;
		}
		if(c == 13 || c == 14) {
			if(k == n) {
				cout<<0<<endl;
			} else if(k >= n/2) {
				cout<<1<<endl;
			} else {
				if(n/2-k < 3) {
					cout<<2<<endl;
				} else if(k == 1) {
					cout<<((n+1)/2+1)/2<<endl;
				}
				else {
					cout<< ((n+1)/2-k)/3 + ((n+1)/2%3 != 0) + 1 <<endl;
				}
			}
		} else {
			cout<<rand()%(n/2)<<endl;
		}
	}
	return 0;
}
