#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],sum[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long l=1,r=1;
	while(l<=r){
		if(r==n+1) break;
		long long s=(r-l+1)*a[r],t=sum[r]-sum[l-1];
		if(s-t>m) l++;
		else{
			ans=max(ans,r-l+1);
			r++;
		}
	}
	cout<<ans;
	return 0;
} 
