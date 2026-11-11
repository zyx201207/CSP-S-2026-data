#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],c,d[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==2){
		a[n+1]==a[1];
		for(long long i=1;i<=n;i++){
			b[i]=a[i]&a[i+1];
		}
		sort(b+1,b+n+1);
		cout<<b[n];
	}
	else if(m==n){
		c=a[1];
		for(long long i=2;i<=n;i++){
			c&=a[i];
		}
		cout<<c;
	}
	else if(m==n-1){
		for(long long i=2;i<=n;i++){
			c=a[1];
			for(long long j=2;j<=n;j++){
				if(i!=j){
					c&=a[j];
				}
			}
			d[i]=c;
		}
		for(long long i=3;i<=n;i++){
			c=a[2];
			c&=a[i];
		}
		d[1]=c;
		sort(d+1,d+n+1);
		cout<<d[n];
	}
	return 0;
} 
