#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
long long c[100005];
long long d[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	bool f=1;
	for(long long i=0;i<n-1;i++){
		b[i]=a[i+1]-a[i];
		if(b[i]!=b[i-1]&&i>0){
			f=0;
		}
	}
	if(f==1){
		long long s=0;
		for(long long i=1;;i++){
			s+=b[1]*i;
			if(s>m){
				cout<<i-1;
				return 0;
			}
		}
	}
	return 0;
}