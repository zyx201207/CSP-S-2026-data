#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int arr[200005];
	int arr1[200005];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n,cmp);
	long long sum=0;
	arr1[0]=arr[0];
	for(int i=0;i<n;i++){
		arr1[i+1]=(arr1[i]&arr[i+1]);
	}
	cout<<arr1[m-1];
	return 0;
}
