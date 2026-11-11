#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],c,d,t;
int read() {
	int f=1,ans=0;
	char ch=getchar();
	if(!isdigit(ch)) {
		if(ch=='-') {
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)) {
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return f*ans;
}
void solve() {
	n=read(),d=read();
	int ans=0;
	for(int i=0; i<n; i++) {
		a[i]=read();
		ans+=a[i];
	}
	cout<<ans/3;		
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--) {
		solve();
	}
	return 0;
}
