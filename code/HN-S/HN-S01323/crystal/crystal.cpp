#include "bits/stdc++.h"
using namespace std;
const int N=5e5;
int b,c;
long long n,m,a[N],ma,z,t,w,e,k[N],l,r,h=2,f,s;
struct st{
	long long x,y;
}p[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1){
			if(a[i]!=a[i-1])b=1;
		}
	}
	if(b==0){
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])c=1;
	}
	if(c==0){
		if(1+(n-1)*(a[2]-a[1])<m)cout<<1+(n-1)*(a[2]-a[1]);
		else{
			while(m){
				m-=a[2]-a[1];
				if(m>0)s+=a[2]-a[1];
			}
			
		}
		return 0;
	}
		for(int i=1;i<=n;i++){
				k[i]=abs(a[i]-a[i-1]);
				if(r+k[i]>m){
					f=max(f,r);
					h=i+1;
				}
				else {
					r+=k[i];	
				}	
			}

	cout<<f;
}
