#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a;
	vector<int> sum(n+1);
	a.push_back(-1);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin()+1,a.end());
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]+=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=upper_bound(sum.begin()+1,sum.end(),i*a[i]-m)-sum.begin();
		if(sum[x-1]>=i*a[i]-m) ans=max(ans,i);
		if(x<=i) ans=max(ans,i);
	}
	cout<<ans;
	return 0;
}