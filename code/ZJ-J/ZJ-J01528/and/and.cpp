#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return ret*f;
}
const int maxn=2e5+5;
int n,m,a[maxn],f[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(m==1){
		int ma=*max_element(a+1,a+n+1);
		cout<<ma;
	}
	else if(m==2){
		int ma=-(1<<30);
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		ma=max(ma,a[i]&a[j]);
	}else if(m==n){
		int cnt=a[1];
		for(int i=2;i<=n;i++)cnt&=a[i];
		cout<<cnt;
	}
	else if(m==n-1){
		f[1]=a[1];int ma=-(1<<30);
		for(int i=2;i<=n;i++)f[i]=f[i-1]&a[i];
		ma=max(ma,f[n]&f[1]);
		for(int i=2;i<=n;i++)
		ma=max(ma,f[i-1]&f[n]&f[i]);
		cout<<ma;
	}
	return 0;
}
