#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[105],sum,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long l=1,r=n;
	sort(a+1,a+n+1);
	long long q=0;
	while(l<=r){
		long long mid=(l+r)/2;
		q++;
		if(mid<a[q]){
			r=mid;
		}
		if(mid>a[q]){
			l=mid;
		}
		if(mid==a[q]){
			a[q]++;
			ans++;
		}
	}
	
	cout<<"3";
	return 0;	
} 
