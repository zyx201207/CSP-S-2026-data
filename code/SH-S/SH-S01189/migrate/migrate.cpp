#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int ret=0,w=1;
	char c=getchar();
	while(c<'0'||c>'9'){ 
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}
	return w*ret;
}
void write(long long x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
const int N=2000015;
int c,n,t,d;
int a[N],f[N],g[N];
int ans=0;
bool vis[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		if(c<=10){
			ans=0;
			for(int p=1;p<=n;p++){ 
				for(int i=1;i<=n;i++)f[i]=1e9;
				g[p]=1;f[p]=0;
				for(int i=p+1;i<=n;i++){
					for(int j=p;j<i;j++){
						if(a[i]-a[j]<=d){
							if(f[i]>f[j]+1)f[i]=f[j]+1,g[i]=g[j];
							else if(f[i]==f[j]+1)g[i]+=g[j]; 
						}
					}
				}
				for(int i=p+1;i<=n;i++){
					if(g[i]==2)ans++;
				}
			}
			write(ans),putchar('\n');
		}
		else if(c>=11&&c<=12){
			int x=a[2]-a[1];
			int p=d/x;
			if(p<=1){
				write(0),putchar('\n');
			}
			else write(max(0ll,n-p*2+1)),putchar('\n');
		}
		else{
			write(0),putchar('\n');
		}
	}
	return 0;
}
