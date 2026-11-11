#include <bits/stdc++.h>

using namespace std;
bool check(long long a,vector<long long> arr,int m,int n){
    for(int i=a-1;i<n;i++){
        long long sum=0;
        for(int j=i-a+1;j<i;j++){
            sum+=arr[i]-arr[j];
            if(sum>m)break;
        }
        if(sum<=m)return true;
    }
    return false;
}
int mylower_bound(vector<long long> arr,int m,int n){
    int left=1,right=n;
	while(left<right){
        long long mid=(right+left)/2;
        if(check(mid,arr,m,n)==true){
            left=mid;
        }else{
            right=mid-1;
        }
   }
	return left;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n=0,m=0;
    cin>>n>>m;
    if(n==0){
    	cout<<0;
    	return 0;
	}
    if(n==1){
    	cout<<1;
		return 0;
	}
    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
     if(arr[0]==arr[n-1]){
        cout<<n;
        return 0;
     }
     long long ans=mylower_bound(arr,m,n);
     cout<<ans;
    return 0;
}

