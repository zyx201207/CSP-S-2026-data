#include<bits/stdc++.h>
using namespace std;
int a[100005];
long long q(long d,long b){
	long long c=0;
	for(int i=d;i<=b;i++){
		c+=a[i]-a[d];
	}
	return c;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,z,x,c;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	z=1,x=0,c=0;
	for(long long i=1;i<=n;i++){
		if(i-1) x+=a[i]-a[z];
		while(x>m){
			x-=q(z,i);
			z++;
		}
		c=max(c,i-z+1);
	}
	cout<<c;
	return 0;
}
