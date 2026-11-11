#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],s[N];
int ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=n;i>=1;i--){
		if(a[i]*(i-1)-s[i]<=m){
			ans=max(ans,i);
			break;
		}
		else{
			int l=1,r=i;
			while(l<=r){
				int mid=(l+r)/2;
				bool f=false;
				if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=m) ans=max(i-mid+1,ans),r=mid-1;
				else l=mid+1; 
			}
			l=1,r=i;
			while(l<=r){
				int mid=(l+r)/2;
				bool f=false;
				if(a[i]*mid-s[mid]<=m) ans=max(mid,ans),l=mid+1;
				else r=mid-1; 
			}
		}
	}
	cout<<ans;
	return 0;
}
