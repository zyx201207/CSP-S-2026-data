#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,i,a[200010],t,w,ans;
char c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	t=1,w=n;
	while(t<w){
		if(c[t]!=c[w]){
			if(a[t]>a[w]) a[t]-=a[w],ans+=a[w],w--;
			else if(a[t]==a[w]) ans+=a[t],t++,w--;
			else a[w]-=a[t],ans+=a[t],t++;
		}
		else{
			if(a[t]>a[w]) a[t]-=a[w],w--;
			else if(a[t]==a[w]) t++,w--;
			else a[w]-=a[t],t++;
		}
	}
	cout<<ans;
	return 0;
}