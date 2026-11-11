#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,x[N];
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<1)+(s<<3)+(ch-'0');ch=getchar();}
	return s*f;
}
signed main(){
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();d=read();
		for(int i=1;i<=n;i++)x[i]=read();
		if(c==11||c==12){
			if(d<=(x[2]-x[1]))printf("0\n");
			else printf("%lld\n",max((int)0,n-2*((int)(d/(x[2]-x[1])))+1));
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+2;j<=n;j++){
					int p=0;
					for(int k=i+1;k<j;k++)
						if((x[k]-x[i])<=d&&(x[j]-x[k])<=d)p++;
					if(p==2)ans++;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
