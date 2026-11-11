#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long maxn=5e5+100;
int n,a[maxn],m,ans=-LONG_LONG_MAX,cnt;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=1;
	while(1){
		while(cnt>m&&l<r){
			cnt-=a[r]-a[l];
			l++;
		}
			ans=max(ans,r-l+1);
		if(r!=n){
			cnt+=(r-l+1)*(a[r+1]-a[r]);
			r++;
		}else {
			break;
		}
//		cout<<cnt<<" ";
	}
	cout<<ans;
	return 0;
}