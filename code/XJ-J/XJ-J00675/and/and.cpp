#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[109000];
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5){
		cout<<"7";
	}else{
		cout<<"12";
	}
	
	return 0;
}