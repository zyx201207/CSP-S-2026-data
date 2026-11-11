#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],cha[N],ans,sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;++i)cha[i]=a[i]-a[i-1];
	sum[1]=0;
	sum[2]=a[2]-a[1];
	for(int i=3;i<=n;++i)sum[i]=sum[i-1]+(i-1)*cha[i];
	int l=1,r=2,ans=0;
	while(l<=n && r<=n){
		int x=sum[r]-(sum[l]+(l-1)*(a[r]-a[l]));
		if(x<=m){
			if(r-l+1>ans)ans=r-l+1;
			r++;
		}
		else l++;
	}
	cout<<ans<<'\n';
	return 0;
}
