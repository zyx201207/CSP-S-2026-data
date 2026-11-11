#include<bits/stdc++.h>
using namespace std;

namespace wsrCSPJ {
	const int N=2e5+9;
	int n,m,a[N];
	bool flag[N];
	
	int main() {
		freopen("and.in","r",stdin);
		freopen("and.out","w",stdout);
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cin>>n>>m;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			flag[i] = 1;
		}
		int tot=0,ans=0; 
		for(int k=30;k>=0;k--) {
			int cnt=0;
			for(int i=1;i<=n;i++) 
				if(flag[i]&&((a[i]>>k)&1)) cnt++;
			if(cnt>=m) {
				ans |= 1<<k;
				for(int i=1;i<=n;i++) 
					if(flag[i]&&((a[i]>>k)&1)) flag[i] = 1;
					else flag[i] = 0;
			}
		}
		cout<<ans;
		return 0;
	}
}

int main() { return wsrCSPJ::main(); }

