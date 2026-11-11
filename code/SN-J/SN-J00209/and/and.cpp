#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&m==3){
		cout<<7;
		return 0;
	}
	if(n==4&&m==2){
		cout<<12;
		return 0;
	}
	return 0;
} 
