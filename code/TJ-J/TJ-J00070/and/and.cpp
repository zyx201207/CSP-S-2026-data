#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	int m;
	cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	if(m==1){
		cout<<arr[n-1];
	}else if(m==2){
		cout<<arr[n-2];
	}else{
		cout<<arr[n-3];
	}
	
	return 0;
} 
