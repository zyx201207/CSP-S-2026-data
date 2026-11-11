#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+1+n);
	int ans=1;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int l=0,r=i;
		while(l+1<r){
			int mid=(l+r)>>1;
			if((1ll*(i-mid)*a[i]-s[i-1]+s[mid-1]) <= m)r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout << ans << '\n';
	return 0;
}
