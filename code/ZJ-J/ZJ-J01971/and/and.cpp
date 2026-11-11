#include <bits/stdc++.h>
using namespace std;
const int N=1e7+5;
long long m,n,sum=0,x=0,h=0;
long long a[N];
long long y(long long q,long long p){
	int z=0,c=1;
	while(q && p){
		if(q%2==1&&p%2==1){
			z+=c;
		}
		q/=2,p/=2;
		c*=2;
	}
	return z;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		x=max(x,a[i]);
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			h=max(h,y(a[i],a[j]));
		}
	}
	if(m==1)	cout<<x;
	if(m==2)	cout<<h;
		
}
