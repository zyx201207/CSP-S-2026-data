#include<bits/stdc++.h>
using namespace std;
const int kmaxn=2e5+1;
int n,a[kmaxn],c[kmaxn],li,lj,ri,rj;
long long int ans;
char x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>x;
		c[i]=x-'a';
	}
	li=1,ri=n,lj=0,rj=a[n];
	while(li<=ri || (li==ri && lj<rj)){
		if(a[li]-lj>rj){
			if(c[li]!=c[ri]){
				ans+=rj;
			}
			lj+=rj,ri--,rj=a[ri];
		}else if(a[li]-lj<rj){
			if(c[li]!=c[ri]){
				ans+=a[li]-lj;
			}
			rj-=a[li]-lj,li++,lj=0;
		}else{
			if(c[li]!=c[ri]){
				ans+=rj;
			}
			li++,lj=0,ri--,rj=a[ri];
		}
		if(lj==a[li])li++,lj=0;
		if(rj==0)ri--,rj=a[lj];
	}
	cout<<ans;
	return 0;
}
