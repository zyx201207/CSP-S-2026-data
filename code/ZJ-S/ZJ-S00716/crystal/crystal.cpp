#include<bits/stdc++.h>
using namespace std;
long long ans[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+1];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		ans[i]=(a[i]-a[i-1])*(i-1)+ans[i-1];
	}
	long long k1=1,k2=1;
	long long maxi=-1;
	for(long long i=1;i<=n;i++){
		if(ans[i]==m){
			maxi=max(i,maxi);
		}
	}
	cout<<maxi;
	return 0;
}

