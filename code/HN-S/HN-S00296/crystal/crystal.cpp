#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){int x = 0,zt = 1;char ch = getchar();while(ch<48||ch>57){if(ch==45)zt = -1;ch = getchar();}while(48<=ch&&ch<=57){x = (x<<3)+(x<<1)+(ch^48);ch = getchar();}return x*zt;}
const int N = 1e6 + 10;
int n,m,ans,sum,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read();m = read();
	for(int i=1;i<=n;i++)a[i] = read();
	sort(a+1,a+1+n);
	for(int l=1,r=1;r<=n;r++,sum+=(a[r]-a[r-1])*(r-l)){
		while(l<r&&sum>m)sum -= a[r]-a[l++];
		ans = max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}