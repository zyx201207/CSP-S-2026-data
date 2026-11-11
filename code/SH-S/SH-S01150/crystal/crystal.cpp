#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],s[500009];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long ans=1,r=1;
	for(long long l=1;l<=n;l++){
		while(r<l)r++;
		while(r<n){
			long long R=r+1;
			long long mid=(l+R)>>1;
			long long len=R-l+1;
			long long sum=a[R]*len-(s[R]-s[l-1]);
			if(sum>m)break;
			r=R;
			ans=max(ans,len);
		}
	}
	cout<<ans;
	return 0;
} 
