#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
const int N=5e5+10;
int n,m;
int a[N];
int s[N];
int ans;
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
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-s[i]+s[mid-1]<=m){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
