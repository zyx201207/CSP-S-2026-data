#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],ans,p[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool fA=1,fB=1;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=i) fA=0; 
	}
	sort(a+1,a+n+1);
	long long x=a[2]-a[1];
	for(int i=3;i<=n;++i) if(a[i]-a[i-1]!=x) fB=0;
	if(fA==1){
		long long s=0;
		for(int i=1;i<=n;++i){
			if(i/2*(i-1)<=m) s=i;
		}
		cout<<s;
		return 0;
	}
	if(fB==1){
		long long ans=0;
		for(int i=1;i<=n;++i){
			if(((a[i]+1)*((a[i]-a[1])/(a[i]-a[i-1]))/2)<=m) ans=i;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;++i){
		long long s=0,cnt=1;
		for(int j=i-1;j>=1;--j){
			if(s+(a[i]-a[j])>m){
				break;
			}
			s+=(a[i]-a[j]);
			++cnt;
		}
		ans=max(ans,cnt); 
	}
	cout<<ans;
	return 0;
}
//zui duo 75pts;kong bei qie
