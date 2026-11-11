#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],maxn=-1e18;
int cha[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int ta=0,tb=0;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n-1;i>=1;--i)cha[i]=a[i+1]-a[i],sum[i]=sum[i+1]+cha[i];
	for(int i=1;i<=n;++i)ta+=(a[i]==i),tb+=(i>=3&&a[i]-a[i-1]==a[i-1]-a[i-2]);
	if(ta==n){
		for(int l=n;l>=1;--l){
			if((sum[l]+1)*(n-l)>(m<<1)){
				cout<<n-l;
				return 0;
			}
		}
		return 0;
	}
	if(tb==n-2){
		for(int l=n;l>=1;--l){
			if((sum[l]+sum[n-1])*(n-l)>(m<<1)){
				cout<<n-l;
				return 0;
			}
		}
	}
	for(int r=1;r<=n;++r){
		int l=r,ans=0;
		while(l>=1&&ans+sum[l]-sum[r+1]<=m){
			ans+=sum[l]-sum[r+1];
			--l;
		}
		maxn=max(maxn,r-l+1);
	}
	cout<<maxn;
	return 0;
}
