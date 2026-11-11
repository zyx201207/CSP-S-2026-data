#include<bits/stdc++.h>
using namespace std;
long long m,n,a[1000005],s[1000005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stable_sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		long long l=1,r=i,ans1=0;
		while(l<=r){
			long long mid=(l+r)/2;
			if(a[i]*(mid)-(s[i]-s[i-mid])<=m){
				l=mid+1;
				ans1=mid;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
}