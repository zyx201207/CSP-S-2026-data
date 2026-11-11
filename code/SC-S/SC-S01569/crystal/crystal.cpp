#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
bool check(long long md){
	for(int i=md;i<=n;i++){
		long long cnt=b[i]-b[i-md];
		if(a[i]*md-cnt<=m)
			return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i]; 
	long long l=1,r=n,ans=-1;
	while(l<r){
		long long md=(l+r)/2;
		if(check(md)){
			ans=max(ans,md);
			l=md+1;
		}else
			r=md-1;
	}
	cout<<ans;
	return 0;
}