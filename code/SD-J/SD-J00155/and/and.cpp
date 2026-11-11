#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N];
int cnt(int x){
	int cnt1=0;
	while(x){
		int r=x%2;
		if(r==1)cnt1++;
		x/=2;
	}
	return cnt1;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	if(n<20){
		int ans1=-1e18;
		for(int mask=0;mask<(1<<20);++mask){
			if(cnt(mask)!=m)continue;
			bool flag=0;
			int ans=0;
			for(int i=0;i<20;++i){
				if(mask&(1<<i)){
					if(flag==0){
						ans=a[i];
						flag=1;
					}
					else ans&=a[i];
				}
			}
			ans1=max(ans1,ans);
		}
		cout<<ans1<<'\n';
	}
	else if(m==1){
		cout<<a[n]<<'\n';
	}
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;++i)ans&=a[i];
		cout<<ans<<'\n';
	}
	else if(m==2){
		int ans=-1e18;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<'\n';
	}
	else if(m==n-1){
		int ans1=-1e18;
		for(int i=1;i<=n;++i){
			int ans=a[1];
			for(int j=2;j<=i-1;++j)ans&=a[j];
			for(int j=i+1;j<=n;++j)ans&=a[j];
			ans1=max(ans1,ans);
		}
		cout<<ans1<<'\n';
	}
	else{
		int ans=a[n];
		for(int i=n-1;i>=n-m+1;--i)ans&=a[i];
		cout<<ans<<'\n';
	}
	return 0;
} 
