#include<bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
int n,m;
uint ans;
vector<int> V;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	V.push_back(114514);
	for(int i=1; i<=n; i++) {
		int t;
		cin>>t;
		V.push_back(t);
	}
	sort(V.begin(),V.end());
	uint l=1,r=1;
	uint len=1;
	int cost=0;
	while(r<n) {
		if(l==r) {
			cost+=(r-l+1)*(V[r]-V[r-1]);
			r++;
			len++;
		}
		if(cost<=m) {
			ans=max(ans,r-l+1);
			cost+=(r-l+1)*(V[r]-V[r-1]);
			r++;
		} else {
			cost-=V[r]-V[l];
			l++;
		}
	}
	cout<<ans<<endl;
	return 0;
}