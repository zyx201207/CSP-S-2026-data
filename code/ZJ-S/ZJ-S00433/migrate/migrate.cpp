#include<bits/stdc++.h>
using namespace std;
const int N=4e6+10;
long long read() {
	long long f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
void write(long long x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9) {
		write(x/10);
	}
	putchar(x%10+'0');
	return;
}
long long c,t,n,d,a[N],ans,b[N],lb,e[N],le;
bool check(long long l,long long r) {
	long long j=l;
	lb=0;
	b[++lb]=l;
	while(1) {
		long long zs=j;
		while(zs<=r&&a[zs]-a[j]<=d) zs++;
		zs--;
		if(zs==j) return 0;
		j=zs;
		if(j==r) break;
		b[++lb]=j;
	}
	bool bo=1;
	b[++lb]=r;
	for(int i=2; i<lb; i++) {
		if(a[b[i+1]]-a[b[i]-1]<=d&&b[i-1]!=b[i]-1) {
			b[i]-=1;
			bo=0;
			break;
		}
	}
	if(bo) return 0;
	j=r;
	le=0;
	e[++le]=r;
	while(1) {
		long long zs=j;
		while(zs>=l&&a[j]-a[zs]<=d) zs--;
		zs++;
		if(zs==j) return 0;
		j=zs;
		if(j==l) break;
		e[++le]=j;
	}
	e[++le]=l;
	for(int i=1; i<=le; i++) {
		if(b[i]!=e[le+1-i]) return 0;
	}
	return 1;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--) {
		n=read(),d=read(),ans=0;
		for(int i=1; i<=n; i++) a[i]=read();
		for(int l=n; l>=1; l--) {
			if(l<n&&a[l+1]-a[l]>d) continue;
			for(int r=l+1; r<=n; r++) {
				if(a[r]-a[r-1]>d) break;
				if(check(l,r)) {
					ans++;
				}
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
