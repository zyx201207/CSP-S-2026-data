#include<bits/stdc++.h>
using namespace std;
int main(){
	 freopen("card.in","r",stdin);
	 freopen("card.out","w",stdout);
	 int n,m,i,a[i]={0};
	 cin>>n>>m;
	 for(i=0;i<=n-1;i++){
	 	cin>>a[i];
	 }
	 for(i=1;i<=n;i++){
	 	if(a[i]<n){
	 		a[i]=n;
		 }
	 }
	 for(int i=1;i<=m;i++){
	 	cout<<a[i];
	 }
 return 0;
 }

