#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
const int N=2e5+7;
int n,m,ans,t;
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[0]=(1ll<<31)-1;
	int now=n;
	for(t=29;t>=0;t--){
		sort(a+1,a+now+1,[](int x,int y){
			return (x>>t&1)>(y>>t&1);
		});
		int l=0,r=now,f=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[mid]>>t&1) l=mid+1,f=mid;
			else r=mid-1;
		}
		if(f>=m){
			now=f;
			ans+=(1ll<<t);
		}
	}
	cout<<ans;
	return 0;
}
