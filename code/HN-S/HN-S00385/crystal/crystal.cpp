#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long qzh[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	bool f=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			f=0;
		}
	}
	if(f){
		long long maxl=0;
		long long x=0;
		for(long long i=2;i<=n;i++){
			x+=(i-1)*(a[i]-a[i-1]);
			if(x>m){
				break;
			}
			maxl=max(maxl,i);
		}
		cout<<maxl;
	}
	else{
		sort(a+1,a+n+1);
		long long maxl=0;
		long long x=0;
		for(int i=1;i<=n;i++){
			x=0;maxl=0;
			for(long long j=i;j<=n;j++){
				x+=(j-i)*(a[j]-a[j-1]);
				if(x>m){
					break;
				}
				maxl=max(maxl,j);
			}
		}
		cout<<maxl;
	}
	
	return 0;
}
