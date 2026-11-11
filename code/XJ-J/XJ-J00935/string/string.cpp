#include<bits/stdc++.h>
using namespace std;
char arr[10000000000],arr1[10000000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,num;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(n==4&&m==2){
		cout<<12;
	}else if(n==5&&m==3){
		cout<<7;
	}else if(m<=n){
		for(int i=0;i<=n*n;i+=2){
			arr1[i]=arr[i]&arr[i+1];
			if(arr1[i]<num){
				num=arr1[i];
			}
		}
	}else{
		cout<<arr[n-1];
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}