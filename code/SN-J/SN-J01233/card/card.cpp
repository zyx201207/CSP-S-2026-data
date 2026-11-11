#include<bits/stdc++.h>
using namespace std ;
int n,a[200005],t[1000005],f,x[1000005],y[200005];
int main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i]+1)f=1;
		t[a[i]]=i;
	}
	if(f==0){
		for(int i=1;i<=n;i++){
	 		if(t[i]!=0)cout<<t[i]<<" "; 
	 		return 0;
		}
	}
	return 0;
}
