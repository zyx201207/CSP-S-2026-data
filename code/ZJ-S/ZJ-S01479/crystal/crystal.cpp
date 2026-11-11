#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long t=1,l=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		l=l*10+ch-'0';
		ch=getchar();
	}
	return t*l;
}
const long long MX=5e5+5;
long long n,m,maxx=-1e9,minn=1e9,ans=1;
long long a[MX];
long long f[MX];
long long xx(long long x){
	memset(f,0,sizeof(f));
	for(long long i=1;i<=n;i++) f[i]=abs(a[i]-x);
	sort(a+1,a+n+1);
	long long s=m;
	long long an=0;
	for(long long i=1;i<=n;i++){
		if(f[i]<=s){
			an++;
			s-=f[i];
		}
		else break;
	}
	return an;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(long long i=1;i<=n;i++){
		a[i]=read();
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	for(long long j=minn;j<=maxx;j++){
		ans=max(ans,xx(j));
	}
	printf("%d\n",ans);
	return 0;
}
