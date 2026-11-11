#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
int f[500010];
int read(){
	int x=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	f[1]=0;
	for(int i=2;i<=n;i++){
		f[i]=f[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int maxn=-1;
	int l=1,r=1;
	int linshi=0;
	for(;l<=n&&r<=n&&l<=r;l++){
		linshi=f[r]-((a[r]-a[l-1])*(l-1)+f[l-1]);
		while(linshi<=m){
			r++;
			linshi=f[r]-((a[r]-a[l-1])*(l-1)+f[l-1]);
		}
		maxn=max(r-1-l+1,maxn);
	}
	cout<<maxn<<'\n';
}
