#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int arr[200005]={};
int arr1[200005]={};
int n,m;
cin>>n>>m;
for(int i=0;i<n;i++){
	cin>>arr[i];	
}
if(m==1){
	sort(arr,arr+n);
	cout<<arr[0];
}
if(m==n){
	for(int i=1;i<n;i++){
		arr[i]=arr[i]&arr[i-1];
	}
	cout<<arr[0];
}
if(m==2){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			arr[i]=max(arr[i],arr[i]&arr[j]);
		}
	}
	sort(arr,arr+n,cmp);
	cout<<arr[0];
}



return 0;
} 

