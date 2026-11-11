#include<bits/stdc++.h>

using namespace std;
long long int arr[500005]={};
int n;
long long m;
bool check(int mid){
	long long int cnt=0;
	for(int i=1;i<=mid;i++){
		cnt+=arr[mid]-arr[i];
	}
	int i=mid;
	while(i<=n){
		if(cnt<=m){
			return 1;
		}
		cnt-=arr[i]-arr[i-mid+1];
		i++;
		cnt+=(mid-1)*(arr[i]-arr[i-1]);
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	int l=1,r=n+1;
	while(l+1!=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	cout<<l;
	return 0;
}

