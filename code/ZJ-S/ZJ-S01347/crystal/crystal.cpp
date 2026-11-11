#include <bits/stdc++.h>
using namespace std;
long long m,a[500010],s[500010];
int n,l,r,t,mid,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for (int i=1;i<=n;i++){
		t=l=1;r=i-1;
		while (l<=r){
			mid=l+r>>1;
			if (a[i]*(i-mid)-s[i-1]+s[mid-1]<=m){
				t=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		ans=max(ans,i-t+1);
	}
	cout<<ans<<"\n";
	return 0;
}
