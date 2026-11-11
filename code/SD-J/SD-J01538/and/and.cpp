#include <bits/stdc++.h>
using namespace std;
long long m,n,a[200010],f[2010][2010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long i,j;
	int ji1=0;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1){
			ji1=1;
		}
	}
	sort(a+1,a+n+1);
	if(m==n){
		long long h=a[1];
		for(i=2;i<=n;i++){
			h=h&a[i];
		}
		cout<<h;
		return 0;
	}
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==2){
		long long h=0;
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				h=max(h,(a[i]&a[j]));
			}
		}
		cout<<h;
		return 0;
	}
	if(m==n-1){
		long long h,hh=0;
		for(i=1;i<=n;i++){
			if(i==1){
				h=a[2];
			}else{
				h=a[1];
			}
			for(j=2;j<=n;j++){
				if(j!=i){
					h=(h&a[j]);
				}
			}
			hh=max(h,hh);
		}
		cout<<hh;
		return 0;
	}
	if(ji1==0){
		for(i=n-1;i>=n-m;i--){
			a[i]=a[i]&a[i+1];
		}
		cout<<a[n-m+1];
		return 0;
	}
	cout<<a[n-m+1];
	return 0;
}
