#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
typedef long long ll;
constexpr int N=5e5+5;

int n,m;
int a[N],b[N];
int ans=1;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
	int l=1,r=1;
	while(l<=r&&r<=n){
		int d=b[r]-b[l-1]+(l-1)*(a[r]-a[l-1]);
		while(d>m&&l<r) ++l,d=b[r]-b[l-1]+(l-1)*(a[r]-a[l-1]);
		ans=max(ans,r-l+1);
		r++;
	}
	cout<<ans;
	return 0;
}
