#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
int ans=0;
long long n,m;
bool check(int mid){
	long long mn=1e18;
	for(int i=mid;i<=n;i++){
		mn=min(mn,a[i]*mid-b[i]+b[i-mid]);
	}
	return mn<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	int l=0,r=n,mid;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	ans=l;
	cout<<ans<<endl;
}

