#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main (){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long r=1;
	long long ans1=1;
	long long k=0;
	for(int l=2;l<=n;l++){
		k+=(l-r)*(a[l]-a[l-1]);
		while(k>m){
			k-=(a[l]-a[r]);
			r++;
		}
		ans1=max(ans1,l-r+1);
	}
	cout<<ans1;
	return 0;
}