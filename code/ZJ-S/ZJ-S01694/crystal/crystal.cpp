#include<bits/stdc++.h>
#define PII pair<int,int>
#define int long long
#define LL long long
using namespace std;
const int inf=0x3f3f3f3f,INF=0x3f3f3f3f3f3f3f3f;
const int tianyiblue=0x66ccff;
int a[500005],sum[500005],n,m,ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;++i){
		int l=1,r=i,res=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)res=mid,r=mid-1;
			else l=mid+1;
		}ans=max(ans,i-res+1);
	}cout<<ans<<'\n';
	return 0;
}

