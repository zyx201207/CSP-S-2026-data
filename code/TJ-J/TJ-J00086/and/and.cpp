#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.on","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<a[n-1]; 
	return 0;
} 
