#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans,mx,sum[N];
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		long long l=1,r=i,mid,anx=0;
		while(l<=r){
			mid=(l+r)>>1;
			if((a[i]*(i-mid+1))-(sum[i]-sum[mid-1])<=m) r=mid-1,anx=mid;
			else l=mid+1;
		}
		ans=max(ans,i-anx+1);
	}
	cout<<ans;
	return 0;
}
