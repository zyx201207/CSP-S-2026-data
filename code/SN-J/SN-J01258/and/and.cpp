#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
	}
	else if(m==n){
		cout<<0;
	}
	else{
		cout<<0; 
	}
	return 0;
}
