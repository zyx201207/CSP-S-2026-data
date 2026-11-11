#include<bits/stdc++.h>
using namespace std;
long long a[500005]={},b[500005]={};
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n;
long long m,ans=1,sum=0,t=0,r;
cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>a[i];
b[i]=b[i-1]+a[i];
}
if(n==1){
	cout<<1;
	return 0;
}
for(int i=1;i<n;i++){
	if((a[i]-a[i-1]==a[i+1]-a[i])==0){
		t=1;
		break;
	}
}
if(t==0){
	r=a[1];
}
sort(a,a+n);
if(t==0){
	for(int i=1;i<=n;i++){
		m-=i*r;
		if(m<0){
			cout<<ans;
			return 0;
		}
		else{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
for(long long i=n;i>=ans;i--){
sum=1;
long long l=1,r=i-1,mid2=i/2;
while(l<r){
	if(m-(a[i]*(i-mid2+1)-(b[i]-b[mid2-1]))>=0){
		r=mid2;
		//cout<<a[i]*(i-mid2+1)<<" "<<b[i]-b[mid2-1]<<'\n';
	}
	else{
		l=mid2+1;
	}
	mid2=(l+r)/2;
	if(l>=r){
		sum=i-l+1;
		break;
	}
}
//cout<<a[i]<<" "<<sum<<'\n';
ans=max(ans,sum);
}
cout<<ans;
return 0;
}
