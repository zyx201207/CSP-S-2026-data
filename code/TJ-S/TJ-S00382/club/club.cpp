#include<bits/stdc++.h>
using namespace std;
long long n,c,t,a[5]={2,1,3,2,1},ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n;
			cout<<a[n%5]<<"\n" ;
	}
	return 0;
} 
/*

*/ 
