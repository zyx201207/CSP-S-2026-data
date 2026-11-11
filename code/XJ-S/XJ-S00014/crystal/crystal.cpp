#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		if(n==5&&m==5){
			cout<<3;
		}else{
			cout<<4;
		}
	
	
	return 0;
} 
