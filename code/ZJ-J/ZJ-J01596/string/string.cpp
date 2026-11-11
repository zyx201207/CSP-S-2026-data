#include<bits/stdc++.h>
using namespace std;
long long n,a[300000],x=1,l=0,y,z;
char c[300000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		x+=a[n];
	}
	y=1,z=n;
	for(;;){
		if(a[y]==0)
			y++;
		if(a[z]==0)
			z--;
		if(y>=z)
			break;
		long long b=min(a[y],a[z]);
		if(c[y]!=c[z])
			l+=b;
		a[y]-=b,a[z]-=b;
	}
	cout<<l;
	return 0;
} 
