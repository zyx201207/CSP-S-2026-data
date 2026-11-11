#include <bits/stdc++.h>
using namespace std;
long long n,i,t,w,ans,a[200010];char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i]>>b[i];
	int t=1,w=n;
	while(t<w)
		if(b[t]==b[w])
			if(a[t]>a[w]) a[t]-=a[w],w--;
			else if(a[t]<a[w]) a[w]-=a[t],t++;
			else t++,w--;
		else
			if(a[t]>a[w]) ans+=a[w],a[t]-=a[w],w--;
			else if(a[t]<a[w]) ans+=a[t],a[w]-=a[t],t++;
			else ans+=a[t],t++,w--;
	cout<<ans;
	return 0;
}
/*
AC
ÆÀ²â»ú±£ÓÓÎÒ 
*/
