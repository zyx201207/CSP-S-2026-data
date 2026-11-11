#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,s[500005],t;
long long mapping(int x,int y){
	return s[x]-s[y]-(y-x)*(a[n]-a[y]);
}
int find(int x){
	int l=1,r=x,mid;
	while(l<r){
		mid=l+(r-l)/2;
		if(mapping(mid,x)<m)r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--)s[i]=s[i+1]+(a[n]-a[i]);
	for(int i=n;i>=1;i--){
		if(m>=mapping(1,i)){
			ans=max(ans,(long long)i);
			break;
		}
		int t=find(i);
		ans=max(ans,(long long)(i-t+1));
	}
	cout<<ans;
	return 0;
}
