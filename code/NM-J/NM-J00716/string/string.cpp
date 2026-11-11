#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[100000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	int z=0;
	for(int i=0;i<n/2;i++){
		if(a[i]!=a[n-i]){
			z++;
		}
	}
	cout<<z;
	return 0;
} 
