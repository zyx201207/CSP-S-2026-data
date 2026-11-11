#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],f[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}
	int l=1,sum=0,ans=1;
	for(int i=2;i<=n;i++){
		sum=a[i]*(i-l+1)-(f[i]-f[l-1]);
		while(sum>m&&l<i) sum-=a[i]-a[l],l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}