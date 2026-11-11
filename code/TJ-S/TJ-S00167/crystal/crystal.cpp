#include<bits/stdc++.h>
using namespace std;
long long n,m,arr[500005],arr1[500005]={},ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	arr1[1]=arr[0];
	for(int i=1;i<n;i++){
		arr1[i+1]=arr1[i]+arr[i];
	}
	for(int i=0;i<n-1;i++){
		int l=i,r=n-1,x;
		while(1){
			x=(l+r+1)/2;
			if((arr[x]*(x-i+1)-arr1[x+1]+arr1[i]>m&&arr[x-1]*(x-i)-arr1[x]+arr1[i]<=m)||x==n-1){
				if(x-i>ans){
					ans=x-i;
				}
				break;
			}
			if(arr[x]*(x-i+1)-arr1[x+1]+arr1[i]>m)r=x;
			else l=x;
			if(l==r)break;
			if(r-i<ans)break;
		}
	}
	cout<<ans;
	return 0;
}


