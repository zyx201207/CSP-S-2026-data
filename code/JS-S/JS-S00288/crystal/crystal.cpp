#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],s[N],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	else{
		sort(a+1,a+1+n);
		bool A=1,B=1;
		if(a[1]!=1) A=0;
		for(int i=2,d=a[2]-a[1];i<=n;i++){
			if(a[i]!=i) A=0;
			if(a[i]-a[i-1]!=d) B=0;
		}
		if(A){
			int ans=(sqrt(1+8*m)-1)/2;
			cout<<ans+1;
		}
		else if(B){
			int d=a[2]-a[1];
			int ans=(sqrt(1+8*m/d)-1)/2;
			cout<<ans+1;
		}
		else{
			for(int l=1;l<n;l++){
				for(int r=l+1;r<=n;r++){
					int val=(r-l)*a[r]-s[r-1]+s[max(0*1ll,l-1)];
					if(val<=m) ans=max(ans,r-l+1);
					else break;
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
