#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long h[500005];
int main(){
	//Oct31==Dec25?
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long m0=m;
	for(long long i=2;i<=n;i++){
		for(long long j=i-1;j>=1;j--){
			if(a[j]+m0>=a[i]){
				m0=m0-a[i]+a[j];
				h[i]++;
			}
			if(m0<=0){
				break;
			}
		}
		m0=m;
	}
	long long s=-1;
	for(long long i=1;i<=n;i++){
		s=max(s,h[i]);
	}
	cout<<s+1;
	return 0;
} 
