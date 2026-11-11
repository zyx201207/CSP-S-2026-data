#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#define int long long

using namespace std;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,M;
	int total=0;
	bool flagA=1, flagB = 1;
	cin>>n>>M;
	vector<int> v(n);
	for (auto &i : v) cin>>i;
	int flagBp = v[1]-v[0];
	flagA = v[0]<=110;
	for (int i=1;i<n;i++){
		if (abs(v[i])>110) flagA = 0;
		if (v[i]-v[i-1]!=flagBp) flagB = 0;
	}
	if (flagA){
		sort(v.begin(),v.end());
		int ans = -10000000;
		for (int ave=v[0];ave<=v[n-1];ave++){
			queue<int> q;
			int m = M;
			auto it = v.begin();
			while (it!=v.end()&&*it<=ave){
				if (m>=ave-*it){
					m-=ave-*it;
					q.push(ave-*it);
					
				}
				else if(!q.empty()){
					m+=q.front();
					q.pop();
					m-=ave-*it;
					q.push(ave-*it);
				}
				++it;
			}
			ans = max((int)q.size(),ans);
		}
		cout<<ans<<endl;
	}
	else if (flagB){
		int c = abs(flagBp);
		int change = 1;
		while (M>=c*change&&change<n) M-=(change++)*c;
		cout<<change<<endl;
	}
	else {
		sort(v.begin(),v.end());
		int ans = -10000000;
		for (int r=0;r<n;r++){
			int m = M;
			int cnt = 0;
			int l = r;
			while (l>=0&&m>=v[r]-v[l]) m-=v[r]-v[l--];
			ans = max(r-l,ans);
		}
		cout<<ans<<endl;
	}
}
