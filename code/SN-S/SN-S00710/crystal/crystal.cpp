#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace zhu{bool ST;
int n,m,a[500500],sum[500500];
bool ED;string main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		while(l<=r){
			int mid=((l+r)>>1);
			if(a[i]*(i-1-mid+1)-(sum[i-1]-sum[mid-1])<=m) r=mid-1;
			else                                          l=mid+1;
		}
		ans=max(ans,i-r);
//		cout<<r+1<<" "<<i<<"\n";
	}
	cout<<ans<<'\n';
	return ".";
}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cerr<<zhu::main()<<'\n'<<(&zhu::ST-&zhu::ED)/1048576.0;
}
/*
5 5
1 2 4 8 9
*/
