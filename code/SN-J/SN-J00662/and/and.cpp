// menkeming fuluzhongxue SN-J00662
#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],ans;
vector<long long>v1,v2;
void solve() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		v1.push_back(a[i]);
	}
	for(long long i=(1ll<<31); i; i>>=1) {
		int f=0;
		v2.clear();
		for(long long x:v1) {
//		cerr<<x<<" "<<i<<" "<<(x&i)<<'\n';
			if((x&i)==i) {
				f++;
//				cerr<<x<<" "<<i<<" "<<(x&i)<<((x&i)==i)<<'\n';
				v2.push_back(x);
			}
		}
		if(f>=m) {
			ans+=i;
			v1=v2;
		}
//		cerr<<f<<" ";
	}
	cout<<ans;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
