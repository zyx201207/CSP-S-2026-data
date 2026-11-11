#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N=2e5+5;

ll a[N];
char c[N];

// O(n)
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
	}
	
	int li=1, ri=n;
	ll lk=a[1], rk=a[n], ans=0;
	while(li<=ri) {
		if(lk>rk) {
			if(c[li]!=c[ri]) {
				ans+=rk;
			} lk-=rk;
			rk=a[--ri];
		} else if(lk<rk) {
			if(c[li]!=c[ri]) {
				ans+=lk;
			} rk-=lk;
			lk=a[++li];
		} else {
			if(c[li]!=c[ri]) {
				ans+=lk;
			} lk=a[++li];
			rk=a[--ri];
		}
	} cout<<ans<<endl;
	
	return 0;
}
