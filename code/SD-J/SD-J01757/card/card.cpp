#include<bits/stdc++.h>
using namespace std;
long long a[1000000],b,c,d,n,q[1000000];
long long f(int x,int w){
	if(x==0){
		c=c&a[w];
	return 0;
	}
	for(int i=x;i<=n;i++){
		f[x-1,i];
		c=c&a[w];
	}
	
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>b;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cout<<a[i];
		
	} 
	return 0;
}
