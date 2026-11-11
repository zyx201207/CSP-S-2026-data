#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,inf=3e18,base=233;
int n,m,a[500005],s[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int res=0,l=i,r=n;
		while(l<=r){
			int mid=l+r>>1;
			if(a[mid]*(mid-i+1)-s[mid]+s[i-1]<=m){
				res=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		ans=max(ans,res-i+1);
		//cout<<i<<" "<<res<<endl;
	}
	cout<<ans;
	
}