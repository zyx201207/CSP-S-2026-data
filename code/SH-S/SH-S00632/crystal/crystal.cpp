#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500002],s[500002],l,r,mid,ans=1;
bool t;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+n+1);
s[1]=a[1];
for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
for(int i=n;i>0;i--){
	l=1,r=i;
	while(l<r){
		mid=(l+r)/2;
		t=(m>=(a[i]*(i-mid))-(s[i-1]-s[mid-1]));
		if(t){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	mid=(l+r)/2;
	ans=max(ans,i-mid+1);
}
cout<<ans;
return 0;
}
