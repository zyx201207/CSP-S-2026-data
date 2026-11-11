#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define re register
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
const int N=5e5+2,M=3e5+2;
int n,m,a[N],st[N],top,vis[M],cnt[M];
void work(int x){
	top=0;
	memset(vis,0,sizeof vis);
	for(re int i=x;i<=n;++i){
		if(vis[a[i]]>0){
			while(st[top]!=a[i]){
				vis[st[top]]--;
				top--;
			}
			vis[st[top]]--;
			top--;
		}
		st[++top]=a[i];
		vis[a[i]]++;
	}
	for(re int i=1;i<=m;++i){
		cnt[i]+=(vis[i]>0?1:0);
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(re int i=1;i<=n;++i) a[i]=read();
	for(re int i=1;i<=n;++i) work(i);
	for(re int i=1;i<=m;++i){
		write(cnt[i]);
		putchar(' ');
	}
	return 0;
}

