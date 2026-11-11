#include <bits/stdc++.h>
#define int long long
using namespace std;
const int PY=1e12;
const int N=1e6+5;
int n,m,ans;
int a[N],pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		a[i]+=PY;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=0,r=i-1,sum=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if((mid+1)*a[i]-(pre[i]-pre[i-mid-1])<=m)
				l=mid+1,sum=l;
			else r=mid-1;
		}
		ans=max(ans,sum);
	}
	cout<<ans<<'\n';
}