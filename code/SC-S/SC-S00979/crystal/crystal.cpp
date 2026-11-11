#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	long long cnt=0;
	int ans=n;
	for(int i=2;i<=n;i++){
		cnt+=(a[i]-a[i-1])*(i-1);
		if(cnt>m){
			cnt-=(a[i]-a[i-1])*(i-1);
			ans=i-1;
			break;
		}
	}
	int l=1,r=ans;
	while(r<n){
		cnt=cnt-(a[r]-a[l]);
		l++;
		while(cnt+(a[r+1]-a[r])*(r-l+1)<=m&&r<n){
			cnt+=(a[r+1]-a[r])*(r-l+1);
			r++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}