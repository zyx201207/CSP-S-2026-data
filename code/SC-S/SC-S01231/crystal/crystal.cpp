#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull signed long long
#define pi pair<int,int>
const int N=5e5+10;
int a[N],s[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(mid*a[i]-(s[i-1]-s[i-1-mid])<=m)ans=max(ans,mid+1),l=mid+1;
			else r=mid-1;
		}
	}
	cout<<ans; 
	return 0;
}