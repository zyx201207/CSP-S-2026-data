#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int w2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)w2=1;
	}
	if(w2==0){
		ans=1;
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(sum+i<=m)ans++;
			sum+=i;
		}
		cout<<ans;
		return 0;
	}
	w2=0;
	long long e=(a[2]-a[1]);
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=e)w2=1;
	}
	if(w2==0){
		ans=1;
		long long sum=0,kw=0;
		for(int i=1;i<=n-1;i++){
			kw+=e;
			if(kw<=m)ans++;
		}
		cout<<ans;
		return 0;
	}
	long long l=1,r=1,sum,r2;
	while(l<=r&&r<=n&&l<=n){
		r2=r+1;
		if(r2>n)break;
		sum=0;
		long long g=-1e18;
		for(int i=l;i<=r2;i++){
			sum+=a[i];
			g=max(g,a[i]);
		}
		if(g*(r2-l+1)-sum<=m){
			r++;
			ans=max(ans,r-l+1);
		}else if(l<r){
			l++;
		}
	}
	cout<<ans;
	return 0; 
}
