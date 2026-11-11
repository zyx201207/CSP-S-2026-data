#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500501],mx=1,sum,hh=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2; i<=n; i++){
		sum+=(a[i]-a[i-1])*(i-hh);
		while(sum>m){
			sum-=(a[i]-a[hh]);
			hh++;
		}
		if(i-hh+1>mx){
			mx=i-hh+1;
		}
	}
	cout<<mx;
	return 0;
}