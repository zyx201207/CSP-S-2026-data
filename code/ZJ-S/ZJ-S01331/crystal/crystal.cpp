#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],b[500005],s[500005],ss[500005],sss[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	int len=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++){
		int p=lower_bound(b+1,b+len+1,a[i])-b;
		sum[p]++;
	}
	for(int i=1;i<=len;i++) s[i]=b[i]*sum[i],ss[i]=ss[i-1]+sum[i],sss[i]=sss[i-1]+s[i];
	ll ans=0;
	for(int i=1;i<=len;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if((b[i]*(ss[i]-ss[mid-1]))-(sss[i]-sss[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		if(l==1){
			ans=max(ans,ss[i]);
			continue;
		}
		int x=m-((b[i]*(ss[i]-ss[l-1]))-(sss[i]-sss[l-1]));
		ans=max(ans,ss[i]-ss[l-1]+x/(b[i]-b[l-1]));
	}
	cout<<ans;
	return 0;
}