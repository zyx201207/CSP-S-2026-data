#include<iostream>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
const int N=5*1e5+3;
int a[N],m,n,ans,num;
bool fa;
inline bool che(int mid){
	int mmax=1e9+3;
	for(int i=1+mid/2;i<=n-mid/2;i++){
		num=0;
		for(int j=i-mid/2;j<=i-mid/2+mid-1;j++) num+=abs(a[j]-a[i]);
		mmax=min(mmax,num);
	}
	return mmax<=m;
}
inline void er(int l,int r){
	while(l<=r){
		int mid=l+(r-l)/2;
		if(che(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int af=a[2]-a[1];
	for(int i=3;i<=100;i++){
		if(a[i]-a[i-1]!=af){
			fa=true;
			break;
		}
	}
	if(fa==false) cout<<m/af+1;
	else{
		er(1,n);
		cout<<ans;
	}
	return 0;
}