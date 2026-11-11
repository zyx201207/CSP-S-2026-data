#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,k,l,x,y,z,s,d,g,h,a[5001000],q,t,w,b[5001000],c[5001000];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(i=3;i<=n;i++) if(a[i]-a[i-1]!=a[i-1]-a[i-2]) break;
	if(i>n){
		q=a[2]-a[1];
		for(i=1;i<=n;i++){
			x=x+i;
			if(x*q>m) break;
		}
		cout<<i-1;
	}
	else{
		for(i=1;i<=n;i++){
			if(a[i]==a[i-1]&&i!=1) c[t]++;
			else t++,b[t]=a[i],c[t]=1;
		}
		for(i=1;i<=t;i++){
			g=m;s=c[i];
			for(j=i-1;j>=1;j--)
				if(g>=(b[i]-b[j])*c[j]) g=g-(b[i]-b[j])*c[j],s+=c[j];
				else break;
			if(j>=1) s+=g/(b[i]-b[j]);
			d=max(d,s);
		}
		cout<<d;
	}
	return 0;
}