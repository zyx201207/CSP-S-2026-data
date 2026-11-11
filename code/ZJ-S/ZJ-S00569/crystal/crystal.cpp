#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500025];
long long p[500025];
bool check(int x){
	for(int i=x;i<=n;i++){
		long long num=p[i]-p[i-x];
		long long need=x*a[i];
		if(num+m>=need) return true;
	}return false;
}int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) p[i]=p[i-1]+a[i];
	int l=1,r=n,ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}cout<<ans;
	return 0;
}
