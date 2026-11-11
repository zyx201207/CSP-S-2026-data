#include<bits/stdc++.h>
using namespace std;
int main(){
	 freopen("string.in","r",stdin);
	 freopen("string.out","w",stdout);
	 long long n;
	 int m,t,i,j,a[i]={0};
	 char c,S;
	 cin>>n;
	 for(i=0;i<=n-1;i++){
	 	cin>>a[i]>>c;
	 }
	 S=a[i]+c;
	 for(i=1;i<=n;i++){
	 	for(j=0;j<=n-i-1;j++){
	 		a[j]=a[j-1];
	 		a[j-1]=t;
	 		a[j]=t;
		 }
	 }
	 m=t;
	 cout<<m;
 return 0;
 }

