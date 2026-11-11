#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll d=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	if(ch=='-') f*=-1,ch=getchar();
	while(ch>='0'&&ch<='9')
	d=(d<<3)+(d<<1)+(ch^48),ch=getchar();
	return d*f;
}
ll n,m,c,d,q,s,e;
ll dis[5005][5005];
ll stat[5005];
ll a[5005][5005];
ll t[5005][5005];
void f(ll s,ll e){
	dis[s][e]=1e18;
	for (ll k=1;k<=m;k++){
		if(dis[s][k]&&dis[k][e]){
			dis[s][e]=min(dis[s][k]+dis[k][e]-2*stat[k],dis[s][e]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for (int i=1;i<=m;i++)
	stat[i]=read();
	for (int i=1;i<=n;i++){
		a[i][0]=read();
		for (int j=1;j<=a[i][0];j++){
			a[i][j]=read(),t[i][j]=read();
			for (int x=1;x<j;x++)
				dis[a[i][j]][a[i][x]]=dis[a[i][x]][a[i][j]]=stat[a[i][j]]+stat[a[i][x]]+t[i][j]+t[i][x];
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=i+1;j<=m;j++)
		if(!dis[i][j]) f(i,j);
	}
	for (int i=1;i<=q;i++){
		s=read(),e=read();
		printf("%lld\n",dis[s][e]);
	}
	
}
