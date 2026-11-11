#include  <bits/stdc++.h>
using namespace std;
long long n;
long long a[1000000009],tnt,v=1,z;
string c[100009];
int  main() {
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	//cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
	}
	z=n;
	while (v<z) {
		if (c[v]!=c[z]) {
			if (a[v]<a[z]) {
				tnt+=a[v];
				a[z]-=a[v];
				v+=1;
			} else if(a[z]<a[v]){
				tnt+=a[z];
				a[v]-=a[z];
				z-=1;
			} else {
				tnt+=a[v];
				z+=1;
				v-=1; 
			}
		
		} else {
			if (a[v]<a[z]) {
				a[z]-=a[v];
				v+=1;
			} else if(a[z]<a[v]){
				a[v]-=a[z];
				z-=1;
			} else {
				z+=1;
				v-=1;
			}
		}	
	}
	cout<<tnt;
	return 0;
}
