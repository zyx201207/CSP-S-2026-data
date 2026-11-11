#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],l,f[200010],ans;
char c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
		f[i]=f[i-1]+a[i];
	}
	for(int i=1,j=l;i<j;){
		int ii=lower_bound(f+1,f+n+1,i)-f;
		int jj=lower_bound(f+1,f+n+1,j)-f;
		int t=min(a[ii],a[jj]);
		if(c[ii]!=c[jj]) ans+=t;
		i+=t,j-=t;
		a[ii]-=t,a[jj]-=t;
	}
	cout<<ans;
	return 0;
}
