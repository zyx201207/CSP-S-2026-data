#include <bits/stdc++.h>
#define int long long
using namespace std;
int f[2000010],n,i,a[2000010],t,w,cntt,cntw,kind,ma,ans;
char c[2000010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(!f[c[i]]) f[c[i]]=1,kind;
	}
	if(kind==1) return cout<<0,0;
	t=1;w=n;
	while(t+1<w){
		if(c[t]!=c[w])
		  if(a[t]>a[w]) ans+=a[w],cntw+=a[w],w--;
		  else if(a[t]<a[w])ans+=a[t],cntt+=a[t],t++;
		  else ans+=a[w],cntw+=a[w],cntt+=a[w],w--;
		else t++,w--;
	}
	ans+=abs(cntt-cntw);
	cout<<ans;
	return 0;
}
/*
Trick||Treat!
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/