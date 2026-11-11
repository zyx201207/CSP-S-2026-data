#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n;long long m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	int ans=0,sum=0;
	for(int i=1,j=1;j<=n;j++){
		sum+=a[i]-a[j];
		while(sum>m){
			sum-=(a[i]-a[i+1])*(j-i);i++;
		}
		ans=max(ans,j-i+1);
		//cerr<<i<<' '<<j<<' '<<sum<<'\n';
	}
	cout<<ans;
	return 0;
}
/*
__/\__
\    /
/_  _\
  \/
*/