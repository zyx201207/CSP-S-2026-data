#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int n,m,ans,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int pre=0;
	for(int i=n,j=n;i>=1;i--){
		int tot=pre,cnt=0;
		for(;j>=1;j--){
			tot+=a[i]-a[j];
			if(tot>m){
				cnt=i-j;
				pre=tot-a[i]+a[j]-(cnt-1)*(a[i]-a[i-1]);
				break;
			}
		}
		if(!cnt){
			cnt=i;
			ans=max(ans,cnt);
			break; 
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
