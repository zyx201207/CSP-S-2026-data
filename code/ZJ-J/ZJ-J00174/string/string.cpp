#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
char ch[200010];
int n,l,r,xl,xr,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>ch[i];
	l=1,r=n;
	xl=a[1],xr=a[n];
	while(l<r){
//		cout<<l<<' '<<r<<' '<<ans<<' '<<xl<<' '<<xr<<'\n';
		if(ch[l]==ch[r]){
			if(xl>xr)  xl-=xr,xr=a[--r];
			else if(xl<xr)  xr-=xl,xl=a[++l];
			else  xl=a[++l],xr=a[--r];
		}
		else{
			if(xl>xr)  xl-=xr,ans+=xr,xr=a[--r];
			else if(xl<xr)  xr-=xl,ans+=xl,xl=a[++l];
			else  ans+=xl,xl=a[++l],xr=a[--r];
		}  
	}
	cout<<ans;
	return 0;
}
