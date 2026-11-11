#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l=1,r=1,sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	while(l<=r&&r<=n){
		if(sum<=m){
			ans=max(ans,r-l+1);
			r++;
			sum+=(a[r]-a[r-1])*(r-l);
		}else{
			sum-=(a[r]-a[l]);
			l++;
		}
	}
	cout<<ans;
	return 0;
}