#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,m,a[2000005],ans;
inline ll read(){
	ll ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t){
		t--;
		n=read(),m=read();ans=0;
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i+3<=n;i++){
			if((a[i+3]-a[i]>m&&a[i+2]-a[i]<=m)&&a[i+3]-a[i+1]<=m) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}