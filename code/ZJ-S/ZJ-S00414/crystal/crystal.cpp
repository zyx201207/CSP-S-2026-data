#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,ans=0;
long long a[N],s[N];
long long check(int l,int r){
	return a[r]*(r-l+1)-(s[r]-s[l-1]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		long long l=1,r=i,anss;
		while(l<=r){
			long long mid=(l+r)>>1;
			if(check(mid,i)<=m){
				r=mid-1;
				anss=i-mid+1;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,anss);
	}
	cout<<ans;
	return 0;
}
