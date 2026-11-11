#include<bits/stdc++.h>
using namespace std;
const long long N=1e6,M=0x7fffffff;
long long n,a[N],s[N],m,ans,minn=M;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long l=1,r=n;
	while(l<r){
		long long mi=(l+r)>>1;
		minn=M;
		for(int i=1;i+mi-1<=n;i++){
			long long x=a[i+mi-1]*mi-s[i+mi-1]+s[i-1];
			minn=min(minn,x);
		}
		if(minn>m){
			r=mi-1;
		}else{
			ans=max(ans,mi);
			l=mi+1;
		}
	}
	cout<<ans;
	return 0;
}
