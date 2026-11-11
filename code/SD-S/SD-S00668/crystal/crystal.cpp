#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,m,a[500005],sum[500005];
bool check(int x){
	long long ans=a[x]*x-sum[x];
	for(int i=x+1;i<=n;i++){
		ans=min(ans,a[i]*x-sum[i]+sum[i-x]);
		//cout<<"---2---\n";
	}
	if(ans<=m)	return 1;
	else	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		//cout<<sum[i]<<" ";
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
		//cout<<"---1---\n";
	}
	cout<<l;
	return 0;
}
