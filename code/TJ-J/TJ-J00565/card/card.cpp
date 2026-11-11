#include <iostream>
using namespace std;
int main(){
	int n,m,sum=0;
	int a[50],b[50];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	b[0]+=1;
	for(int i=0;i<=m;i++){
		i+=1;
		if(a[i]!=a[i+1]){
			b[i+1]+=1;
		}
		if(a[i]==a[i+1]){
			b[i]+=1;
		}
	}
	for(int i=0;i<=m;i++){
		cout<<b[i];
	}
	return 0;
} 
