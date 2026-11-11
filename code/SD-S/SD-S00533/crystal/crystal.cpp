#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N],s[N];
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	s[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=0,r=i,res=n+1;
		while(l<=r){
			int mid=(l+r)>>1;
			if( a[i]*(i-mid)-(s[i]-s[mid])<=m ){
				res=mid;r=mid-1;
			}else l=mid+1;
		}
//		cout<<i<<':'<<res<<' '<<a[i]*(i-res)-(s[i]-s[res])<<endl;
		ans=max( i-res,ans );
	}
	cout<<ans<<endl;
	return 0;
}
/*
不知为何而生存的你我，也不知为何而死去。 
*/
