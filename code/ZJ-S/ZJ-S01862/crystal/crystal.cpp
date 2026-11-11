#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,k,ans=0;
int a[N],sa[N],q[N];

signed main(){
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sa[i]=a[i]+sa[i-1];
	int l=1;
	for(int i=1;i<=n;i++){
		while(l<=i&&a[i]*(i-l+1)-(sa[i]-sa[l-1])>m)l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
