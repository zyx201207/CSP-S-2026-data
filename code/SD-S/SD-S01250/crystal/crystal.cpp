#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],ans;
int get(int l,int r){return (r-l+1)*a[r]-b[r]+b[l-1];}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	int r=1;
	for(int l=1;l<=n;l++){
		while(get(l,r+1)<=m&&r<n)r++;
		if(r-l+1>ans){
			ans=r-l+1;
		}
	}
	printf("%lld",ans);
	return 0;
}
