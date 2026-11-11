//Ñîð©Ñ­ SN-S00488 
#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace sol{
	int a[500005];
	void main(){
		int n,m;
		cin >> n >> m;
		for(int i = 1;i <= n;++i){
			cin >> a[i];
		}
		
		sort(a+1,a+1+n);
		
		int ans = 0,sum = 0;
		queue<int> q;
		
		for(int i = 1;i <= n;++i){
			while(!q.empty() && a[i]*q.size() - sum > m){
				sum -= q.front();
				q.pop();
			}
			ans = max(ans, (int)q.size()+1);
			
			q.push(a[i]);
			sum += a[i];
		}
		
		cout << ans << endl;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	sol::main();
}
