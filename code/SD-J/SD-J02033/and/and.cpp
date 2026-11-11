#include<bits/stdc++.h>
using namespace std;
int main(){
	 freopen("and.in","r",stdin);
	 freopen("and.out","w",stdout);
	 int n,m,b,c,i,a[i]={0};
	 int maxx;
	 cin>>n>>m;
	 for(i=0;i<=n-1;i++){
	 	cin>>a[i];
	 }
	 for(i=0;i<=n;i++){
	 	if(a[i]&a[i+1]==maxx){
	 		b=a[i]&a[i+1];
	 		cout<<b;
		 }else{
		 	c=a[i]&a[n-i-1];
		 	cout<<c;
		 }
    }
 return 0;
 }

