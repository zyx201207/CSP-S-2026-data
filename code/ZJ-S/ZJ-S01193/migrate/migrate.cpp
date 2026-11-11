#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+ch-48,ch=getchar();
	return ret*f;
}
const int maxn=2e6+5;
ll c,T,n,d;
ll x[maxn];
int dp[5005][5005],dis[5005][5005];
bool vis[5005][5005];
void solve(){
	n=read();d=read();
	for(int i=1;i<=n;i++)x[i]=read();
	if(c==11||c==12){
		ll dx=x[2]-x[1];
		ll k=d/dx;
		ll res=0;
		if(k==0){printf("0\n");return;}
		for(int i=1;i<k;i++)res+=n-i;
		for(int i=k;i<n;i+=k)res+=n-i;
		printf("%lld\n",n*(n-1)/2-res);
		return;
	}
	ll res=0;
	for(int i=1;i<n;i++)for(int j=i,k=1;j<n;k++)while(j<n&&x[j+1]-x[i]<=k*d)j++,dis[i][j]=k;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int cnt=0;
			if(x[j]-x[i]<=d)continue;
			for(int k=i+1;k<j;k++)if(dis[i][k]+dis[k][j]==dis[i][j]){
				cnt++;
				if(cnt>2)break;
			}
			if(cnt==2)res++;
			
		}
	}
	printf("%lld\n",res);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();T=read();
	while(T--)solve();
	return 0;
}