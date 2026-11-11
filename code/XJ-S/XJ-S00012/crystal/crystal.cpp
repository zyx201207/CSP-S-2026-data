#include<bits/stdc++.h>
using namespace std;
long long a[500010],s[500010],ans=0,n,m;
bool check(long long mid){
	long long time=1e18;
	for(long long i=1;i+mid-1<=n;i++){
		time=min(time,mid*a[i+mid-1]-(s[i+mid-1]-s[i-1]));
	}
	return time<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	long long l=1,r=1e18; 
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

