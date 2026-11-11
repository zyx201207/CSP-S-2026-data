#include<bits/stdc++.h>
using namespace std;
long long n;
long long m,a[500005],s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	s[0]=0;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}sort(a+1,a+1+n); 
	for(long long i=1;i<=n;i++){
		s[i]=a[i]-a[i-1];
	}
	long long l=1,r=1,ans=1;
	long long b=0;
	while(r<=n){
		//cout<<l<<" "<<r<<" "<<b<<"\n";
		ans=max(ans,r-l+1);
		if(r==n){
			r++;
			continue;
		}
		
		if(s[r+1]*(r-l+1)+b<=m){
			b+=s[r+1]*(r-l+1);
			r++;
		}else{
			b-=a[r]-a[l];
			l++;
		}
		if(l>r) r=l;
	}
	cout<<ans;
}