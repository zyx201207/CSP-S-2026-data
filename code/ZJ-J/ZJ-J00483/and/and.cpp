#include<bits/stdc++.h>
using namespace std;
unsigned int n,m;
vector<unsigned int> V;
vector<unsigned int> dp;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	dp.resize(m+10,0);
	V.push_back(UINT_MAX);
	for(unsigned int i=1; i<=n; i++) {
		unsigned int t;
		cin>>t;
		V.push_back(t);
	}
	sort(V.begin()+1,V.end());
	for(unsigned int i=1; i<=n; i++) {
		for(unsigned int j=m; j>=1; j--) {
			if(j==1) {
				dp[j]=max(dp[j],V[i]);
			} else {
				dp[j]=max(dp[j],dp[j-1]&V[i]);
			}
		}
	}
	cout<<dp[m]<<endl;
	return 0;
}