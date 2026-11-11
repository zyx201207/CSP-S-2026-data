#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,d;
int a[N],f[N];
int nextx(int x){
	int l=x,r=n,ans=l;
	while (l<=r){
		int mid=(l+r)/2;
		if (a[mid]-a[x]>d){
			r=mid-1;
		}else {
			ans=mid,l=mid+1;
		}
	}
	return ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C,T;
	cin >> C >> T;
	while (T--){
		cin >> n >> d;
		for (int i=1;i<=n;i++) cin >> a[i];
		if (C==11||C==12){
			for (int i=n;i>=1;i--) a[i]-=a[i-1];
			a[1]=0;
			if (d<=a[2]) cout << 0 << '\n';
			else cout << max(n-d/a[2]*2+1,0LL) << '\n';
			continue;
		}
		for (int i=1;i<=n;i++) f[i]=nextx(i);
		int ans=0;
		for (int i=1;i<=n;i++) {
			for (int j=f[i]+1;j<=f[f[i]];j++){
				if (a[f[f[i]-1]]>=a[j]&&a[f[f[i]-2]]<a[j]) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

