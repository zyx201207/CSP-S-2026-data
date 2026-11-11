#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=a[i-1]){
			a[i]+=a[i];
		}
	}
	cout<<a[i];
	
	
	
	
	
	return 0;
}
