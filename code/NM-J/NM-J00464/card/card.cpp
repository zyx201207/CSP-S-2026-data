#include <iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n-1;j++){
			if(a[i]==a[j]){
				a[0]==a[j];
			}else{
				
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}
