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
ll n,c,t,d,okv,num,ans;
ll a[500005];
bool b[5005][5005],ok;
ll dis[5005];
void dfs(ll s,ll v,ll cnt){
	if(s==v){
		if(!ok)
		okv=cnt,ok=1,num++;
		else if(cnt==okv)
		num++;
		return ;
	} 
	for (ll cc=v;cc>=s;cc--){
		if(b[s][cc])
			dfs(cc,v,cnt+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	for (ll x=1;x<=t;x++){
		n=read(),d=read(),ans=0;
		for (ll i=1;i<=n;i++){
			a[i]=read();
			for (ll j=i-1;a[i]-a[j]<=d&&j>=1;j--)
			b[j][i]=1;
		}
		for (ll i=1;i<=n;i++){
			for (ll j=i+1;j<=n;j++){
				ok=0;
				dfs(i,j,0);
				if(num==2)
				ans++;
				num=0,ok=0;
			}
		}
		memset(b,0,sizeof(b));
		printf("%lld\n",ans);
	}
}
