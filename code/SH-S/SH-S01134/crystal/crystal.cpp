#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009];
long long l=0,r=0;
long long ans,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	while(l<=n&&r<=n){
		while(r<=n&&cnt<=m){
			ans=max(ans,r-l+1);
			r++;
			cnt+=(r-l)*(a[r]-a[r-1]);
		}
		while(l<=r&&cnt>m){
			l++;
			cnt-=(a[r]-a[l-1]);
		}
	}
	cout<<ans<<endl;
	return 0;
} 
