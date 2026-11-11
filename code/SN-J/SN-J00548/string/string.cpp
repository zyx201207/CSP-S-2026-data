#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define vi void
using namespace std;

const int N=2e5+5;

struct sr {
	ll n;
	char c;
} T[N];

ll n,ans;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>T[i].n>>T[i].c;
	}
	int l=1,r=n;
	while(l<r) {
		auto a=T[l],b=T[r];
//		cout<<l<<' '<<r<<' '<<a.n<<' '<<b.n<<' '<<a.c<<' '<<b.c<<endl;
		if(a.n>b.n) {
			if(a.c!=b.c) {
				ans+=b.n;
			}
			r--;
			T[l].n-=b.n;
		} else if(a.n<b.n) {
			if(a.c!=b.c) {
				ans+=a.n;
			}
			l++;
			T[r].n-=a.n;
		} else {
			if(a.c!=b.c) {
				ans+=a.n;
			}
			l++;
			r--;
		}
//		cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
