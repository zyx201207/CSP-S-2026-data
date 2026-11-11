#include<bits/stdc++.h>
using namespace std;

namespace wsrCSPJ {
	const int N=5e5+9;
	int n,m,a[N];
	
	// brute force
	void solve1() { 
		vector<int>ans(m+1);
		for(int i=1;i<=n;i++) {
			vector<int>cnt(m+1);
			vector<int>v;
			for(int j=i;j<=n;j++) {
				if(cnt[a[j]])
					while(v.back()!=a[j]) {
						cnt[v.back()]--;
						v.pop_back();
					}
				else {
					v.push_back(a[j]);
					cnt[a[j]]++;
				}
			}
			for(int x:v) ans[x]++;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	
	void solve2() {
		vector<int>ans(m+1);
		for(int i=1;i<=n;i++) ans[a[i]]++;
		for(int i=1;i<=m;i++) {
			ans[i] += ans[i-1];
			cout<<ans[i]<<" ";
		}
	}
	
	int main() {
		freopen("card.in","r",stdin);
		freopen("card.out","w",stdout);
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		bool AA=1;
		for(int i=1;i<n;i++)
			if(a[i]>a[i+1]) {
				AA = 0;
				break;
			}
		if(n<=5000) solve1(); // bf O(n^2) 48 pts
		else if(AA) solve2(); // te shu A O(n+m) 4 pts
		return 0;
	}
}

int main() { return wsrCSPJ::main(); }
/*
only 352 pts this time? too low
why can't i ak csp-j???
*/
