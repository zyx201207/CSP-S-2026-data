#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long ans=0;
long long a[1000000];
long long n,m;
int check(int x){
	int sum=0;
	for(int i=x-1;i>=1;i--){
		sum=sum+(a[x]-a[i]);
		if(sum>m){
			return 0;
		}
		
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	int l=1,r=n,mid;
	while(l<=r){
		mid=(r-l)/2+l;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
}
