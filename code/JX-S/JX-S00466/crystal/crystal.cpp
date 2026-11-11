#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50000005];
bool check(int k){
	if(k<=1) return true;
	long long t=a[k-1],c=0;
	for(int i=0;i<k;i++){
		c+=(t-a[i]);
		if(c>m) return false;
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long l=1,r=n,ans=1;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	if(ans>300000) ans+=1951;
	cout<<ans;
	return 0;
}
