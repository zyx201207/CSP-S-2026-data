#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long pr[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pr[i]=pr[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		long long tmp=(i-1)*a[i]-pr[i-1];
		if(m<tmp){
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
} 
