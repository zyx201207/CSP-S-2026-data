#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[500005];
bool check(int ans){
	for(int i=ans;i<=n;i++){
		long long tmp=t[i]-t[i-ans+1]-(i-ans)*(a[i]-a[i-ans+1]);
		if(tmp<=m)return 1;
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
	for(int i=2;i<=n;i++){
		t[i]=t[i-1]+(i-1)*(a[i]-a[i-1]);
	} 
	long long l=0,r=n;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<r;
}
