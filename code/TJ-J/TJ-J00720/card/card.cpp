#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long 

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int>vec(n+1);
	vector<int>ans(m+1,-1); 
	for(int i=1;i<=n;i++){
		cin>>vec[i];
		ans[vec[i]]=max(ans[vec[i]],i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
