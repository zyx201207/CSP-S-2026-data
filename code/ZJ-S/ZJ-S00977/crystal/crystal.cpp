#include <bits/stdc++.h>
using namespace std;

long long a[500005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	
	long long ans=0;
	long long sum=0,l=1;
	for(long long r=1;r<=n;r++){
		sum+=a[r];
		while(a[r]*(r-l+1)-sum>m){
			sum-=a[l];
			l++;
		}ans=max(ans,r-l+1);
	}
	
	cout<<ans;
	return 0;
}
