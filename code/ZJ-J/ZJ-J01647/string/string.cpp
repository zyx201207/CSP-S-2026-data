#include<bits/stdc++.h>
using namespace std;

namespace wsrCSPJ {
	using ll=long long;
	const int N=2e5+9;
	int n,a[N];
	ll L;
	char c[N];
	
	int main() {
		freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i]>>c[i];
			L += a[i];
		}
		ll ans=0,mid=L/2,cnt=0;
		int j=n;
		for(int i=1;i<=n;i++) {
			int nowil=min(1ll*a[i],mid-cnt);
			int sum=0;
			while(sum<nowil) {
				int nowL=min(nowil-sum,a[j]);
				if(c[i]!=c[j]) ans += nowL;
				sum += nowL;
				a[j] -= nowL;
				if(a[j]==0) j--;
			}
			cnt += nowil;
			if(cnt==mid) break;
		}
		cout<<ans;
		return 0;
	}
}

int main() { return wsrCSPJ::main(); }

