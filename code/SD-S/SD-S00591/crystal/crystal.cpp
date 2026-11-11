#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
namespace Rain_Cloud{
	const int N=5e5+7;
	long long a[N],m,sum[N];
	int n;
	bool chk(int mid){
		for(int l=1;l+mid-1<=n;l++){
			int r=l+mid-1;
			long long ret=a[r]*(1LL*mid)-(sum[r]-sum[l-1]);
			if(ret<=m) return 1;
		}
		return 0;
	}
	void RainS(){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
		}
		int l=1,r=n,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(chk(mid)){
				ans=mid;
				l=mid+1;
			}else r=mid-1;
		}
		cout<<ans;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Rain_Cloud::RainS();
	return 0;
}
