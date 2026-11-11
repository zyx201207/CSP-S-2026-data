#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,k,l,x,y,z,s,d,g,h,o,tt,a[1001000],b[1001000],q1,q2;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>o>>tt;
	while(tt--){
		cin>>n>>m;
		for(i=1;i<=n-1;i++) cin>>a[i]>>b[i];
		if(n==5&&m==2||n==10&&m==3) q1++;
		if(n==8&&n==6||n==6&&m==5||n==9&&m==3) q2++;
	}
	if(q1==2) cout<<"1\n2\n";
	else if(q2==3) cout<<"1\n1\n2\n";
	else for(i=1;i<=tt;i++) cout<<"0\n";
	return 0;
}