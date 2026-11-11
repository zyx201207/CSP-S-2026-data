#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],f[N],t=0,len,aa,ans=1;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	f[1]=1;
	len=1;
	aa=a[1];
	for(int i=2;i<=n;i++){
		f[i]=f[i-1]+1;
		int x=(a[i]-aa)*len;
		while(x+t>m){
			x-=(a[i]-a[i-len]);
			len--;
			f[i]--;
		}
		t+=x;
		aa=a[i];
		len++;
		ans=max(f[i],ans);
	}
	cout<<ans;
	return 0;
}


