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
int n,m,a[500010],b[500010],len,ans[500010],p;
bool f;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		len=0;
		for(int j=i;j<=n;j++){
			f=0;
			for(int k=1;k<=len;k++){
				if(b[k]==a[j]){
					f=1;
					p=k;
					break;
				}
			}
			if(f){
				len=p;
				b[len]=a[j];
			}else{
				len++;
				b[len]=a[j];
			}
		}
		for(int j=1;j<=len;j++) ans[b[j]]++;
	}
	printf("%d",ans[1]);
	for(int i=2;i<=m;i++){
		printf(" %d",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
