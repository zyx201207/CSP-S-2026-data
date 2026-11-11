#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1,num=0;
	while(r<=n){
		while(l<=r&&num>m){
			num-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
		r++;
		num+=(a[r]-a[r-1])*(r-l);
	}
	cout<<ans;
	return 0;
}
