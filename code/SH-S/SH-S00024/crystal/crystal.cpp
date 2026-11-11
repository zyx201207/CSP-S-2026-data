#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=514514;
int n,m,a[N],s[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*(i-mid)-(s[i-1]-s[mid-1])<=m){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}
			else l=mid+1;
		}	
	}cout<<ans<<'\n';
	return 0;
}
