#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005];
bool cmp(long long qwert,long long qwerty){
	return qwert>qwerty;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		s[i]=a[i]-a[i-1];
	}
	long long ans=1;
	for(long long i=2;i<=n;i++){
		long long mf=0,as=1;
		for(long long j=1;j<i;j++){
			mf+=a[i]-a[i-j],as++;
			if(m-mf<a[i]-a[i-j-1])break;
		}
		ans=max(as,ans);
	}
	cout<<ans;
	return 0;
}
