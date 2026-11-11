#include<bits/stdc++.h> 
using namespace std;
int n,m,ans,mid=1;
long long a[500005],s[500005],x;
int f(int l,int rr){
	int r=rr;
	while(l<r){
		mid=(l+r)/2;
		int t=rr-mid+1;
		if(t*a[rr]-s[rr]+s[mid-1]<=m) r=mid;
		else l=mid+1;
	}
	return mid;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x=min(x,a[i]);	
	}
	if(x>0) x=0;
	sort(a+1,a+n+1);
	s[0]=0;
	for(int i=1;i<=n;i++){
		a[i]+=abs(x);
		s[i]=s[i-1]+a[i];
	}
	int z=1;
	for(int i=2;i<=n;i++){
		z=f(z,i);
		ans=max(i-z+1,ans);
	}
	cout<<ans;
    return 0;
}