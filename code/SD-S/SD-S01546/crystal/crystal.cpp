//freopen checked?

#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N=5e5+5;
int n,m,a[N],pre[N];

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;//19768503
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	int l=0,res=0,ans=0;
//	a[0]=a[1];
	for(int i=1;i<=n;++i) {
		if(i>1)pre[i]=pre[i-1]+(a[i]-a[i-1])*(i-l-1);
		++res;
		while(pre[i]>m)--res,pre[i]-=a[i]-a[++l];
		if(res==n&&pre[i]<m)--res;
//		if(ans<res)cout<<a[i]<<"\n";
//		if(a[i]==71) {
//			cout<<l<<" "<<pre[i]<<" "<<ans<<" "<<res<<"\n";
//			
//		}
		
		ans=max(ans,res);
	}
	cout<<ans<<"\n";
	return 0;
}
//finished at 15:39:56
//writer:Danny_F61
//luoguid:1813223
