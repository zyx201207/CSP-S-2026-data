#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
const int N=5e5+7;
int n,m;
int a[N],sum[N]; 
inline int qs(int l,int r){
	return sum[r]-sum[l-1];
}
int ans=0;
/*
5 5
1 2 4 8 9
*/
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n) sum[i]=sum[i-1]+a[i];
	rep(i,1,n){
		int l=1,r=i,pos=-1; 
		while(l<=r){
			int mid=l+r>>1;
			if((i-mid+1)*a[i]-qs(mid,i)<=m) pos=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,(i-pos+1));
	} 
	cout<<ans<<"\n";
	return 0;
} 
