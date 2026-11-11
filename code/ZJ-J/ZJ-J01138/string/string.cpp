#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,k,l,x,t,s,d,g,h,u,w,ht,hw,lt,lw;
char p,xt,xw;
struct no{
	char x;
	int y;
}a[200100];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i].y>>a[i].x;
	ht=1;hw=n;lt=a[1].y;lw=a[n].y;
	while(ht<hw){
		xt=a[ht].x;xw=a[hw].x;
		l+=min(lt,lw);
		if(xt!=xw) d+=min(lt,lw);
		if(lt==lw) ht++,hw--,lt=a[ht].y,lw=a[hw].y;
		else if(lt<lw) ht++,lw=lw-lt,lt=a[ht].y;
		else hw--,lt=lt-lw,lw=a[hw].y;
	}
	cout<<d;
	return 0;
}