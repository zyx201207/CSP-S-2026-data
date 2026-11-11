#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=5e5+10;
ll c,n,m,d,q;
ll w[MAXN],a[MAXN];
ll read(){
	char x;
	ll f=1,num=0;
	x=getchar();
	while(x<'0'||x>'9'){
		if(x=='-')f=-1;
		x=getchar();
	}
	while(x>='0'&&x<='9'){
		num=num*10+(x-'0');
		x=getchar();
	}
	return num*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=n;i++){
		w[i]=read();
	}
	for(int i=1;i<=q;i++){
		printf("%d",i);
	}
	return 0;
}
