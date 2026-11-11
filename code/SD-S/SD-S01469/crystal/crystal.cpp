#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while ('0'<=c && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m;
int a[N+5],b[N+5],f[N+5];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	} 
	int num=0,pos=1;
	f[1]=1;
	for (int i=2;i<=n;i++){
		if (a[i]==a[i-1]){
			f[i]=f[i-1]+1;
			continue;
		}
		num+=(i-pos)*b[i];
		f[i]=f[i-1]+1;
		while (num>m){
			num-=(a[i]-a[pos]);
			f[i]--;
			pos++;
		}
	}
	int maxx=-1;
	for (int i=1;i<=n;i++){
		maxx=max(maxx,f[i]);
	}
	printf("%lld",maxx);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
5 5
1 2 4 8 9

7 8
1 3 6 7 9 12 17
*/
