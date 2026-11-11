#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int arr[500010]={};
int arr2[500010]={};
int ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++){
		arr2[i]=arr2[i-1]+arr[i];
		int left=1,right=i;
		while(left<=right){
			int mid=(left+right)/2;
			if(arr[i]*(i-mid+1)-(arr2[i]-arr2[mid-1])<=m){
				ans=max(ans,i-mid+1);
				right=mid-1;
			}
			else{
				left=mid+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
