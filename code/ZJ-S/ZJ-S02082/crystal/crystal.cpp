#include<bits/stdc++.h>
#define endl '\n'
#define mp make_pair
#define pii pair<int,int>
#define int long long
using namespace std;
int n,m,a[500005],s[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
