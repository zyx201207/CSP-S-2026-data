#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],s[500001],l,r,ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(long long i=1;i<=n;i++){
		l=1;
		r=i;
		while(l<r){
			if((i-(l+r)/2+1)*a[i]-s[i]+s[(l+r)/2-1]<=m) r=(l+r)/2;
			else l=(l+r)/2+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
