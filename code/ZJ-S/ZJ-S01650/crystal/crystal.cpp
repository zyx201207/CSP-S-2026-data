#include<bits/stdc++.h>
using namespace std;
// crystal
int n;
long long m,a[500050],ans=LONG_LONG_MIN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<=n;i++){
		long long ysum=0;
		for(int j=i-1;j>0;j--){
			ysum+=(a[i]-a[j]);
			if(ysum>m)break;
			long long h=i-j;
			ans=max(ans,h);
		}
	}
	cout<<ans+1<<'\n';
	return 0;
}
