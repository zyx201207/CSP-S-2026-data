#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,i,t,w,ans,a[200100];
char c[200100];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i]>>c[i];
	t=1;w=n;
	while(t<w){
		if(c[t]!=c[w]){
			if(a[t]>a[w])ans+=a[w],a[t]-=a[w],w--;
			else ans+=a[t],a[w]-=a[t],t++;
		}
		else{
			if(a[t]>a[w])a[t]-=a[w],w--;
			else a[w]-=a[t],t++;
		}
	}
	cout<<ans;
	return 0;
}