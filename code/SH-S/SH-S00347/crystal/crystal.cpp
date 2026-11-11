#include<bits/stdc++.h>
using namespace std;
long long n,m,mx,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=1;i<=n;++i){
			int sum=0,ans=0;
			for(int j=i;j>=1;--j){
				sum+=(a[i]-a[j]);
				if(sum<=m) ans++;
			}
			if(ans>mx) mx=ans;
		}
		cout<<mx;
	}else{
		int sum=0,ans=0;
		for(int j=n;j>=1;--j){
			sum+=(a[n]-a[j]);
			if(sum<=m) ans++;
		}
		if(ans>mx) mx=ans;
		cout<<mx;
	}
	return 0;
}
