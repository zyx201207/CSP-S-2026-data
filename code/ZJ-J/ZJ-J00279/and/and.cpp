#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
int read() {
	int x=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,a[200010],maxn=-2e9,maxx=-2e9;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}else if(m==n){
		maxn=a[1]&a[2];
		for(int i=3;i<=n;i++){
			maxn=maxn&a[i];
		}
		cout<<maxn;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}else if(m==n-1){
		maxn=a[2];
		for(int j=3;j<=n;j++){
			maxn=maxn&a[j];
		}
		maxx=max(maxx,maxn);
		for(int i=2;i<=n;i++){
			maxn=a[1];
			for(int j=2;j<=n;j++){
				if(j==i) continue;
				maxn=maxn&a[j];
			}
			maxx=max(maxx,maxn);
		}
		cout<<maxx;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
