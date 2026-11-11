#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long l=1,r=1,sum=a[1];
	while(r<=n){
		if(sum+m>=(r-l+1)*a[r]){
			ans=max(ans,r-l+1);
			r++;
			sum+=a[r];
		}
		else{
			sum-=a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}