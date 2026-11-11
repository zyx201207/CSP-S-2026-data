#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
long long a[N],sum[N];
long long m;
int n;

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);

	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}

	for(int i=1;i<=n;i++){
		if((i-1)*a[i]-sum[i-1]>m){
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
}

