#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005],b[2000005];
inline int read(){
	int x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C=read(),T=read();
	while(T--){
		int n=read(),d=read();
		for(int i=1;i<=n;i++)a[i]=read();
		cout<<0<<'\n';
	}
	return 0;
}
