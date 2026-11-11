#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
const int MAXN=2e6+5;
i128 x[MAXN];
i128 dis[MAXN];
i128 pre[MAXN];
i128 ans=0;
i128 read(){
	i128 f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-f;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void write(i128 x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9){
		write(x/10);
	}
	putchar((x%10)+'0');
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	c=read();
	t=read();
	while(t--){
		ans=0;
		i128 n,d;
		n=read();
		d=read();
		for(int i=1;i<=n;i++){
			x[i]=read();
			dis[i]=x[i]-x[i-1];
			if(i!=1){
				pre[i]=pre[i-1]+dis[i];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(pre[j]-pre[i]>d){
					if(pre[j]-pre[i]>2*d){
						break;
					}
					if(j-i==3){
						ans++;
						break;
					}
				}
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
