#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],s[500001],ans=1;
long long calc(long long l,long long r){
	return (r-l+1)*a[r+1]-s[r]+s[l-1];
}
long long search(long long l,long long r,long long y){
	int mid,minn=y+1;
	while(l<=r){
		mid=(l+r)/2;
		if(calc(mid,y)>m)
			l=mid+1;
		else{
			minn=min(minn,mid);
			r=mid-1;
		}
	}
	return minn;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1])
			continue;
		long long mx=i,c=1-search(1,i-1,i-1);
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j])
				mx=j;
			else
				break;
		}
		ans=max(ans,c+mx);
		i=mx;
	}
	cout<<ans;
	return 0;
}
