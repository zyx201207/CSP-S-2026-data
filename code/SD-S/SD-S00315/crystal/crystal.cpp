#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define Endl '\n'
using namespace std;
int n,m;
int a[500005],sum[500005];
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid,pos=-1;
		while(l<=r){
			mid=l+r>>1;
			if((i-mid+1)*a[i]-sum[i]+sum[mid-1]<=m){
				r=mid-1;
				pos=mid;
			}else l=mid+1;
		}
		if(pos!=-1)
			ans=max(ans,i-pos+1);
	}
	cout<<ans<<endl;
	return 0;
}
