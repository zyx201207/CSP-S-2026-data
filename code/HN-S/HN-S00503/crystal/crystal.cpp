#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500000],sum[500000];
int s;
bool check(int x){
	for(int i=1;i<=n;i++){
		if(sum[i]+m>x){//前缀和加数大于中等 
			s=i;
//			cout<<sum[i]+m<<" "<<x<<" "<<i<<"\n";
			return 1;
		}
	}
	return 0;
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long l=0x3f3f3f3f,r=-0x3f3f3f3f,mid;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		r=max(r,a[i]);
		l=min(l,a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	sort(a,a+n+1);
//	cout<<l<<" "<<r<<"\n"; 
while(l<r){
	mid=(l+r+1)>>1;
	if(check(mid))l=mid+1;
	else r=mid-1;
}
for(int i=sum[s]+m;i>=2;i--){
	if((sum[s]+m)%i==0&&(sum[s]+m)/i>=a[s]){
		cout<<i;
	return 0;
	}
}
/*
 5 5
 1 2 4 8 9
 
  5 8
-3 -1 2 2 7

*/
	return 0;
}
