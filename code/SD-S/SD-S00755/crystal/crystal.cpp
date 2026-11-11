#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500009];
int l=1,r=1,t=0,ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(;r<=n;r++){
		if(r==1)continue;
		int d=a[r]-a[r-1];
		t=(r-l)*d+t;
		while(l<r&&t>m){t-=(a[r]-a[l]);l++;}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}

