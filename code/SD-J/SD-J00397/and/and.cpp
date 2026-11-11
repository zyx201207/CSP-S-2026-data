#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define re register
#define int long long
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
const int N=2e5+5;
int n,m,a[N],ans,cho[N];
bool vis[N][35];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(re int i=1;i<=n;++i){
		a[i]=read();
		int c=a[i],pos=0;
		while(c){
			if(c&1) vis[i][pos]=1;
			c>>=1;
			++pos;
		}
	}
	for(re int i=1;i<=n;++i) cho[i]=1;
	for(re int j=30;j>=0;--j){
		int res=0;
		for(re int i=1;i<=n;++i){
			if(cho[i]&&vis[i][j]) res++;
		}
		if(res>=m){
			for(re int i=1;i<=n;++i){
				if(!(vis[i][j]&&cho[i])) cho[i]=0;
			}
			ans+=(1<<j);
		}
	}
	write(ans);
	return 0;
}
