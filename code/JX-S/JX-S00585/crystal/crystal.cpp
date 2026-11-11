#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],b[N],sum[N];
int f(int mid,int i){
	return a[i]*(i-mid)-sum[i-1]+sum[mid-1];
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)	sum[i]=sum[i-1]+a[i];
	for(int i=2;i<=n;i++){
		int l=0,r=i-1;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(f(mid,i)>m)	l=mid;
			else r=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans<<'\n';
	return 0;
}
