#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	long long x=1;
	long long ans=0;
	for(int i=2;i<=n;i++){
		while(x<=i){
			long long k=i-x+1;
			long long y=k*a[i]-b[i]+b[x-1];
			if(y<=m){
				break;
			}
			x++;
		}
		ans=max(ans,i-x+1);
	}
	cout<<ans;
	return 0;
} 
