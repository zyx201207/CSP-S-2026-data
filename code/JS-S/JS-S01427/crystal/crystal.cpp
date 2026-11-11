#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],s[500005];
bool ck(long long x){
	for(int i=1;i<=n-x+1;i++){
		long long sum=0;
		sum=x*a[i+x-1]-(s[i+x-1]-s[i-1]);
		if(sum<=m){
			return 1;
		}
	}
	return 0;
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	s[i]=s[i-1]+a[i];
	long long l=1,r=n,ans;
	while(l<r){
		long long mid=(l+r)/2;
		if(ck(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	cout<<ans;
	return 0;
}
