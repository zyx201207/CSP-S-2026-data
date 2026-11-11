#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
const int mod=998244353;
const int inf=1e18;
int n,m;
int a[N];
int sum[N];
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	//for(int i=1;i<=n;i++) cout<<sum[i]<<" ";
	//cout<<"\n";
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		//二分长度
		while(l<r){
			int mid=(l+r+1)>>1;
			if((a[i]*mid-(sum[i]-sum[i-mid+1-1]))<=m) l=mid;
			else r=mid-1;
		}
		//cout<<l<<"\n";
		ans=max(ans,l);
	}
	cout<<ans<<"\n";
	return 0;
}
