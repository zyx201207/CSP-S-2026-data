#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],sum[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int mx=0;
	for(int R=1;R<=n;R++){
		int l=0,r=R,L=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if((R-mid)*a[R]-(sum[R]-sum[mid])<=m){
				r=mid-1;
				L=mid;
			}
			else l=mid+1;
		}
		mx=max(mx,R-L);
	}
	cout<<mx<<"\n";
	return 0;
}