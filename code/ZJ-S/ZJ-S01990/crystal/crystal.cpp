#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[500005],v[500005],maxn=1,d;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=10000){
		sort(a+1,a+1+n);
		for(int i=1;i<=n-1;i++){
			v[i]=a[i+1]-a[i];
		}
		for(int i=1;i<=n-1;i++){
			long long h=0,g=1;
			for(int j=i+1;j<=n;j++){
				h=h+(j-i)*v[j-1];
				if(h>m) break;
				g++;
			}
			maxn=max(maxn,g);
		}
		cout<<maxn;
	}
	else{
		d=max(a[2]-a[1],a[1]-a[2]);
		long long bb=m/d;
		if(m<1) cout<<1;
		else{
			for(int i=1;i<=n-1;i++){
				if(bb>=i*(i+1)/2&&bb<(i+1)*(i+2)/2){
					cout<<i+1;
					return 0;
				}
			}
			cout<<n;
		}
	}
	return 0;
}
