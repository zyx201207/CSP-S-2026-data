#include<iostream>
#include<algorithm>
using namespace std;
long long n,m;
long long arr[900001];
int main(){
	std::ios::sync_with_stdio(false);
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	long long zz=arr[(n-1)/2];
	for(int i=0;i<n;i++){
		if(arr[i]-zz>=0){
			arr[i]-=zz;
		}
	    else{
	    	arr[i]=zz-arr[i];
		}
	}
	long long js=0;
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		m-=arr[i];
		if(m<0){
			cout<<js;
			return 0;
		}
		js++;
	}
	cout<<js;
	return 0;
} 
