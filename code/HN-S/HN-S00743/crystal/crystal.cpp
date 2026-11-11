#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long ans,cnt,t;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=n+1,r=n;
	while(l>=1&&r>=1){
		l--;
		int z=a[r]-a[l]; 
		t+=z;
		if(t>m){
			t-=(a[r]-a[r-1])*(r-l);
			r--;
		}
		cnt=r-l+1;
		if(cnt>ans){
			ans=cnt;
		}
	}
	cout<<ans;
	return 0;
} 
