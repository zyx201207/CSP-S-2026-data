#include<bits/stdc++.h>
using namespace std;
long long a[500000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	for(long long i=n/2;i<=n;i++){
		long long z=m,d=0;
		d++;
		for(long long j=i-1;j>=1;j--){
			if(a[i]-a[j]<=z){
				z=z-(a[i]-a[j]);
				d++;
			}
		}
		maxx=max(d,maxx);
	}
	cout<<maxx;
	return 0;
} 
