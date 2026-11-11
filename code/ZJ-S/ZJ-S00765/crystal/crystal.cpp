#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,i,a[N],s[N],l,r,mid,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(i=1;i<=n;i++){
		l=1;r=i;
		while(l<=r){
			mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m)
				r=mid-1,ans=max(ans,i-mid+1);
			else l=mid+1;
		}
	}
	cout<<ans;
}