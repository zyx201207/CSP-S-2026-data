#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y,u,v,n,m,q,d,c,k[100005],ans,w[100005],a[1005][1005],t[1005][1005],i,j;
ll read() {
	ll k=0;
	ll f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') {
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
void write(ll x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x<10) {
		putchar(x+'0');
	} else {
		write(x/10);
		putchar(x%10+'0');
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(i=1; i<=m; i++) {
		w[i]=read();
	}
	for(i=1; i<=n; i++) {
		k[i]=read();
		for(j=1; j<=k[i]; j++) {
			a[i][j]=read();
			t[i][j]=read();
		}
	}
	while(q--){
		x=read();
		y=read();
		ans=0;
		for(i=x;i<=y;i++){
			ans+=w[i];
		}
		write(ans);
	}
	return 0;
}