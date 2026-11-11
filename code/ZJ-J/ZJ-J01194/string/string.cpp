#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,p;
int a[200010];
char c[200010];
int x,y,xx,yy;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	xx=1,yy=n;
	while(1){
		p=min(a[xx]-x,a[yy]-y);
		if(c[xx]!=c[yy]) ans=ans+p;
		x+=p;
		y+=p;
		if(x==a[xx]) x=0,xx++;
		if(y==a[yy]) y=0,yy--;
		if(xx>=yy) break;
	}
	cout<<ans;
	return 0;
}