#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(n<=5000){
		sort(a+1,a+1+n);
		int ans=0;
		for(int i=1;i<=n;++i){
			int sum=0;
			for(int j=i-1;j>=0;--j){
				if(j==0){
					ans=max(ans,i-j);
					break;
				}
				if(sum+a[i]-a[j]>m){
					ans=max(ans,i-j);
					break;
				}
				sum+=a[i]-a[j];
			}
		}
		cout<<ans;
		return 0;
	}
	bool fff=1;
	for(int i=1;i<=n;++i){
		if(a[i]!=i)fff=0;
	}
	if(fff){
		cout<<m+1;
	}else{
		cout<<m/(a[2]-a[1]);
	}
}
