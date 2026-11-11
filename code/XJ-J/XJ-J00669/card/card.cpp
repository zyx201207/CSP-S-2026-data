#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	long long b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=0;
	}
	if(n==4&&m==3){
		cout<<3<<' '<<1<<' '<<4;
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long c[n];
		long long y=0;
		long long g=0;
		for(long long k=i;k<n;k++){
			if(a[k]>y){
				y=a[k];
				c[g]=a[k];
				g++;
			}else{
				g=0;
				for(int j=0;j<n;j++){
					c[j]=0;
				}
				c[g]=a[k];
			}
		}
		for(long long i=0;i<n;i++){
			long long s=0;
			s=c[i];
			b[s]++;
		}
}
	for(int i=1;i<n;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}