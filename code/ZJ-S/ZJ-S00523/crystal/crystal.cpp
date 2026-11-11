#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m,cnt=0;
bool water(int x){
	long long h=0;
	for(int i=1;i<x;i++){
		h+=a[x]-a[i];
	}
	for(int i=1;i+x<=n;i++){
		if(h<=m) return 1;
		long long kk=a[i+x-1]-a[i];
		h=h-kk+(a[i+x]-a[i+x-1])*x;
	}
	if(h<=m) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(water(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
