#include<bits/stdc++.h>
#define int long long
#define inl inline
const int N=5e5+10;
using namespace std;
int n,m;
int a[N],s[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,ans2=i;
		while(l<=r){
			int mid=(l+r)/2;
			if((i-mid)*a[i]-(s[i-1]-s[mid-1])<=m){
				r=mid-1;
				ans2=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-ans2+1);
	}
	cout<<ans<<endl;
	return 0;
}