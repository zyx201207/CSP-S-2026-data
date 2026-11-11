#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500001];
long long b[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(long long i=n;i>=1;i--){
		long long x=i*a[i]-b[i];
		if(m>=x){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
