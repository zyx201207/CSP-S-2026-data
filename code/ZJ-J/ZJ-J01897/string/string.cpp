#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define int long long
using namespace std;
int n,i,t,w,ans,a[200010];char c[200010];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i]>>c[i];
	t=1;w=n;
	while(t<=w){
		if(a[t]==a[w]){
			if(c[t]!=c[w]) ans+=a[t];
			t++;w--;
		}
		else if(a[t]<a[w]){
			if(c[t]!=c[w]) ans+=a[t];
			a[w]-=a[t];t++;
		}
		else if(a[t]>a[w]){
			if(c[t]!=c[w]) ans+=a[w];
			a[t]-=a[w];w--;
		}
	}
	cout<<ans;
	return 0;
}
