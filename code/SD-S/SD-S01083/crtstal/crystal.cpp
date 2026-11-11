#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500100],n,m,s[500100],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int f=1;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])
		f=0;
	}
	if(f==1){
		if(a[3]-a[2]==0){
			cout<<n;
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(i*a[i]>s[i]+m){
				cout<<i-1;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i*a[i]>s[i]+m){
			for(int j=1;j<=i;j++){
				if((i-j)*a[i]<=s[i]-s[j-1]+m){
					ans=max(ans,i-j);
					break;
				}
			}
		}
		else
		ans=max(ans,i);
	}
	cout<<ans;
	return 0;
}
