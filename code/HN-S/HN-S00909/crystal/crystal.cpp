#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10;
int n,m;
int a[maxn];
int di[maxn];
int sum[maxn];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		di[i]=(i-1)*a[i]-sum[i-1];
		int l=-1,r=i;
		while(l+1<r){
			int mid=(l+r)/2;
			if(di[i]-(a[i]*mid-sum[mid])<=m){
				r=mid;
			}else{
				l=mid;
			}
		}
		di[i]-=(a[i]*r-sum[r]);
		ans=max(ans,i-r);
	}
	cout<<ans;
	return 0;
}
//
