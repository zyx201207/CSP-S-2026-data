#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005],ans=-1,pd=1;
int main(){
	long long n,m;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
sort(a+1,a+1+n);
for(int i=1;i<=n;i++){
	s[i]=s[i-1]+a[i];
}
long long l=1,r=n,mid;
while(l<=r){
	pd=0;
	mid=(l+r)/2;
	for(int i=1;i<=n-mid+1;i++){
	
		if(a[i+mid-1]*(mid-1)-(s[i+mid-2]-s[i-1])<=m){
			pd=1;
		
		}
	}
	if(pd==1){
		l=mid+1;
		ans=mid;
	}
	else{
		r=mid-1;
	}
}
	cout<<ans;
	return 0;
} 
