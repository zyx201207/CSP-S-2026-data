#include<bits/stdc++.h>
using namespace std;
long long n,l,r,ans,m,a[500005],s,sum;
bool check(long long x){
	s=0;
	sum=0;
	for(int i=1;i<=x;i++) s+=a[x]-a[i];
	sum=s;
	for(int i=x+1;i<=n;i++){
		s-=a[i-1]-a[i-x];
		s+=(x-1)*(a[i]-a[i-1]);
		sum=min(sum,s);
	}
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	l=1;
	r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
