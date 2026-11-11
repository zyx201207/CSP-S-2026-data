#include<bits/stdc++.h>
using namespace std;
int dp[20001];
bool cmp(int a,int b){
	return a>b;
}
int main(){	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(m==1){
		sort(arr,arr+n,cmp);
		cout<<arr[0];
		return 0;
	}
	if(n==m){
		long long ans=arr[0];
		for(int i=0;i<n;i++){
			ans=ans&arr[i];
		}
		cout<<ans;
		return 0;
	}
	if(n-1==m){
		sort(arr,arr+n,cmp);
		long long ans=arr[0];
		for(int i=0;i<n-1;i++){
			ans=ans&arr[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans=max(ans,arr[i]&arr[j]);
			} 
		}
		cout<<ans;
		return 0;
	}
	return 0;
} 
