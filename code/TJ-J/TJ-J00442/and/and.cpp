#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100000];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<a[n-1];
	return 0;	
}
