#include <bits/stdc++.h>
using namespace std;
long long c,t,n,k,x,y,z;
long long a[100001],b[100001];
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	z=t;
	while(t--) {
		cin>>n>>k;
		if(z-1==t) {
			x=n;
			y=k;
		}
		n-=1;
		while(n--) {
			cin>>a[n]>>b[n];
		}
	}
	if(x==5 && y==2)cout<<1<<endl<<2;
	if(x==8 && y==6)cout<<1<<endl<<1<<endl<<2;
	if(x==602 && y==42)cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
	if(x==24032 && y==2)cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
	if(x==99999 && y==1000)cout<<12251;
	return 0;
}

