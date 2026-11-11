#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n;
long long m,gc;
const int N=1e6;
long long arr[N],sum[N],dp[N];
bool dc2=true;
int qh(int d){
	int sum=0;
	for(int a=d;a<=n;a++){
		int t=0;
		for(int b=a-d+1;b<a;b++){
			t+=arr[a]-arr[b];
			if(b=a+d-1)
				sum=t;
		}
		sum=min(sum,t);
		}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(int a=1;a<=n;a++) 
		cin>>arr[a];
	sort(arr+1,arr+n+1);
	gc=arr[2]-arr[1];
	for(int a=2;a<=n;a++){
			if(arr[a]-arr[a-1]!=gc)
				dc2=false;
		}
		
	
	if(dc2){
		dp[1]=0;
		for(int a=2;a<=n;a++)
			dp[a]=a*(a-1)/2*gc;
		if(m>n*(n-1)/2*gc){
			cout<<n;	
			return 0;
		}
		for(int a=1;a<=n-1;a++){
			if(dp[a]<=m&&dp[a+1]>m){
				cout<<a;
				return 0;
			}
			
		}
	}
	else{
		dp[1]=0;
		for(int a=2;a<=n;a++){
			dp[a]=qh(a);
		}
		if(m>dp[n]){
			cout<<n;
			return 0;
		}
		for(int a=1;a<=n-1;a++){
			if(dp[a]<=m&&dp[a+1]>m){
				cout<<a;
				return 0;
			}
		}
		
		
	}
		

	

	return 0;
}
