#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ma,a[1000010],sum[1000010];
bool check(int mid,int i){
	int x=a[i]*mid-(sum[i-1]-sum[i-mid-1]);
	if(x<=m)return 1;
	else return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);int xx=abs(a[1]);
	for(int i=1;i<=n;i++) a[i]+=xx;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=0,r=i-1,bao=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)) bao=mid,l=mid+1;
			else r=mid-1;
		}
		ma=max(ma,bao);
	}
	cout<<ma+1;
}