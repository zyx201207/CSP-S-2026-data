#include<bits/stdc++.h>
#define int long long
namespace EVA{
	inline int read(){
		int x=0,f=1;
		char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-') f^=1;
			c=getchar();
		}
		while(c>='0'&&c<='9'){
			x=(x<<3)+(x<<1)+(c^48);
			c=getchar();
		}
		return f?x:~x+1;
	}
	inline void write(int x){
		if(x<0) putchar('-'),x=~x+1;
		if(x>9) write(x/10);
		putchar((x%10)^48);
	}
	inline void spaceput(int x){
		write(x);putchar(' ');
	}
	inline void output(int x){
		write(x);putchar('\n');
	}
}
using namespace EVA;
using namespace std;
const int N=5e5+5;
int n,m,ans=1;
int a[N],d[N],s[N];
//d[i]±Ì æd[i+1]-d[i] 
inline int check(int l,int r){
	int len=r-l;
	int x=s[r-1]-s[l-1],y=a[r];
	int ccc=y*len-x;
	if(ccc<=m) return 1;
	return 0;
}
signed main(){
//	system("fc crystal4.ans crystal.out"); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;i++){
		int l=1,r=i-1,pos=1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)) pos=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-pos+1);
	}
	write(ans);
	return 0;
}
