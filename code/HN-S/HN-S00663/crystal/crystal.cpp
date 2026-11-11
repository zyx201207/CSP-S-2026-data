#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,s=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
    for(int i=0;i<n;i++){
		s+=(i*(a[i]-a[0]));
		if(m<s&&a[i]!=a[i+1]){
			cout<<i+1;
			break;
		}
	}
	return 0;
} 
