#include<bits/stdc++.h>
#define int long long
#define debug printf("!!!\n")
using namespace std;
int read(){
	char c=getchar();
	int x=0,f=1;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void write(int x,char c){
	write(x);putchar(c);
}
const int N=5005;
int _,n,d,a[N],b[N],f[N],p[N],ans,g[N],s[N];
pair<int,int> c[N];
int calc1(int l,int r){
	for(int i=1;i<=n;i++) a[i]=f[i]=g[i]=s[i]=p[i]=0;
	for(int i=l,j=1;i<=r;i++,j++) a[j]=b[i];
	int n=r-l+1,pos=1;
	for(int i=2;i<=n;i++){
		for(;pos<=i&&a[i]-a[pos]>d;pos++);
		p[i]=pos;
	}
	f[1]=0;
	for(int i=2;i<=n;i++) f[i]=f[p[i]]+1;
	for(int i=2;i<=n;i++){
		int l=p[i],r=i,pos,tmp=f[p[i]];
		for(;l<=r;){
			int mid=l+r>>1;
			if(f[mid]==tmp) l=mid+1,pos=mid;
			else r=mid-1;
		}
		c[i]=make_pair(p[i],pos);
	}
	g[1]=s[1]=1;
	for(int i=2;i<=n;i++){
		g[i]=s[c[i].second]-s[c[i].first-1];
		s[i]=s[i-1]+g[i];
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(g[i]==2) res++;
	}
	return res;
}
void calc(int l,int r){
	for(int i=l;i<=r;i++) ans+=calc1(i,r);
}
void solve(){
	ans=0;
	n=read();d=read();
	for(int i=1;i<=n;i++) b[i]=read();
	int lst=1;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]>d) calc(lst,i-1),lst=i;
	}
	calc(lst,n);
	write(ans,'\n');
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	_=read();
	for(int t=read();t--;solve());
	return 0;
}
/*
0 1
8 3
0 1 2 4 8 10 11 13
*/