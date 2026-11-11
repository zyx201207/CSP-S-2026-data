//10:14 AC all simple
#include<bits/stdc++.h>
using namespace std;
const int maxa=200005;
int n,m,a[maxa],ge[50],xx=-1,ans,vis[maxa];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		for(int j=30;j>=0;j--) if(a[i]&(1<<j)) ge[j]++;
	}
	for(int j=0;j<=30;j++) if(ge[j]>=m) xx=j;
	if(xx==-1) printf("0\n");
	else if(ge[xx]==m){
		ans=2147483647;
		for(int i=1;i<=n;i++) if(a[i]&(1<<xx)) ans&=a[i];
		printf("%d\n",ans);
	}else{
		int ss=0,mge=0;
		for(int j=30;j>=0;j--){
			ss=0;
			if(ge[j]>=m){
				ans+=(1<<j);
				mge++;
				for(int i=1;i<=n;i++)
				 if(a[i]&(1<<j)) vis[i]++;
			}
			for(int i=1;i<=n;i++) if(vis[i]==mge) ss++;
			if(ss<m){
				for(int i=1;i<=n;i++)
				 if(a[i]&(1<<j)) vis[i]--;
				ans-=(1<<j);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
