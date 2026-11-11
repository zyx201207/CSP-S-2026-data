#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,i,x,rs,t,w,ans;
char bh,ch;
struct no{
	int x,y;
}a[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bh='A';
	for(i=1;i<=n;i++){
		cin>>x>>ch;
		if(ch==bh) a[rs].x+=x;
		else a[++rs].x+=x,a[rs].y=ch;
		bh=ch;
	}
	t=1;w=rs;
	while(t<w){
		if(a[t].y==a[w].y){
			if(a[t].x>a[w].x) a[t].x-=a[w].x,w--;
			else if(a[t].x<a[w].x) a[w].x-=a[t].x,t++;
			else t++,w--;
		} 
		else{
			if(a[t].x>a[w].x) a[t].x-=a[w].x,ans+=a[w].x,w--;
			else if(a[t].x<a[w].x) a[w].x-=a[t].x,ans+=a[t].x,t++;
			else ans+=a[t].x,t++,w--;
		}
	}
	cout<<ans;
	return 0;
}