#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int N=5e5+666;
int read(){
	int res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=(res<<1)+(res<<+3)+(c^48);
		c=getchar();
	}
	return res*f;
}
void print(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		print(x/10);
	}
	putchar((x%10)^48);
}
int n,m,a[N],pre[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		pre[i]=pre[i-1]+a[i];
	}
	int l=1;
	for(int i=1;i<=n;++i){
		while(l<i&&((i-l+1)*a[i]-(pre[i]-pre[l-1]))>m)++l;
		ans=max(ans,i-l+1);
	}
	print(ans);
	return 0;
}
