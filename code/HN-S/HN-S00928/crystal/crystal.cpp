#include<bits/stdc++.h>
using namespace std;
long long n,m,z,l=99999,r=-99999,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	l=1;
	r=n;
	z=(l+r)/2;
	long long a[n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	while(l<r){
		bool cmp=false;
		for(long long i=0;i+z<=n;i++){
			int sum1=0;
			for(long long j=i;j<i+z;j++){
				sum1+=a[j];
			}
			if(sum1+m==a[i+z-1]*z){
				cmp=true;
				sum=max(sum,z);
				i=n-z+1;
			}
		}
		if(cmp==true){
			l=z;
			z=(l+r)/2;
		}else{
			r=z;
			z=(l+r)/2;
		}
		if(l+1==r){
			for(long long i=0;i+l<=n;i++){
				int sum1=0;
				for(long long j=i;j<i+l;j++){
					sum1+=a[j];
				}
				if(sum1+m==a[i+l-1]*l){
					cmp=true;
					sum=max(sum,l);
					i=n-z+1;
				}
			}
			for(long long i=0;i+r<=n;i++){
				int sum1=0;
				for(long long j=i;j<i+r;j++){
					sum1+=a[j];
				}
				if(sum1+m==a[i+r-1]*r){
					cmp=true;
					sum=max(sum,r);
					i=n-r+1;
				}
			}
			break;
		}
	}
	cout<<sum;
	return 0;
}
