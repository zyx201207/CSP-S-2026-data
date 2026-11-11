//张芃浩 西安交通大学附属中学 SN-S00346 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],pre[500005],m,ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(r>l){
			int mid=(l+r)>>1;
			if(m>=a[i]*(i-mid+1)-(pre[i]-pre[mid-1]))r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
