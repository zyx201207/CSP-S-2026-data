#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m;
int a[maxn];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1,l=1,r=1,now=a[1];
	while(l<=n&&r<=n){
		while(r<n&&(r-l+1)*a[r+1]-now<=m){
			r++;
			now+=a[r];
		}
		ans=max(ans,r-l+1);
		now-=a[l];
		l++;
	}
	cout<<ans<<"\n";
}
