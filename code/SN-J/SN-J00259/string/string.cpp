#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200002],a1[200002],c=0,c1=0;
	char b[200002],b1[200002];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		
	}
	for(int i=0;i<n;i++){
		for(int j=n-1;j>=0;j--){
			b1[i]=b[j];
		}
	}
	for(int i=0;i<n;i++){
		if(b[i]==b1[i]){
			c++;
		}
	}
	if(c==n){
		cout<<0;
	} 
	return 0;
} 
