#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005],ans;
long long fun(long long s,long long w,long long h){
	if(h==m){
		return s;
	}
	for(long long i=w+1;i<n;i++){
		return fun(a[i],i,h+1)&s;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=n-1;i>=0;i--){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		ans=max(fun(a[i],i,1),ans);
	}
	cout<<ans;
	return 0;
}
