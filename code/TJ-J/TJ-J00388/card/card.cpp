#include<bits/stdc++.h>
using namespace std;
int n,m,arr[1000001],arr1[1000001],arr2[1000001],k;
bool cmp(int a,int b){
	if(a==b){
		b=0;
	}
	return a>b;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n,cmp);
	for(int i=0;i<n;i++){
		arr2[i]=arr[i];
	}
	for(int i=0;i<n;i++){
		if(n==0){
			break;
		}
		k=arr[i];
		for(int j=0;j<n;j++){
			if(k==arr[j]){
				for(int m=j;i<n;i++){
					arr[m]=0;
					i=n-m;
				}
			}
		}
		arr1[i]=k;
		n--;
	}
}
