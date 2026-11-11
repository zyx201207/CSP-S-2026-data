#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=505;
const int maxm=5e5+5;
int c,n,m,d,q;
ll w[maxm];
struct GYY{
	int u;ll t;
	bool operator <(const GYY &B)const{return t>B.t;}
};
vector<GYY> p[maxm];
int read(){
	int tot=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')tot=tot*10+ch-'0',ch=getchar();
	return tot*f;
}
ll readll(){
	ll tot=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')tot=tot*10+ch-'0',ch=getchar();
	return tot*f;
}
ll f[maxn][maxn];
void floyd(){
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)w[i]=readll();
	memset(f,63,sizeof f);
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		int k=read();
		for(int j=1;j<=k;j++){
			int u=read();ll t=readll();
			for(auto v:p[u]){
				int id=v.u;ll tt=v.t;
				f[i][id]=f[id][i]=min(f[id][i],tt+t);
			}
			p[u].push_back((GYY){i,t});
		}
	}
	floyd();
	while(q--){
		int s=read(),t=read();
		ll ans=1e18;
		for(auto i:p[s]){
			int x=i.u;
			for(auto j:p[t]){
				int y=j.u;
				ans=min(ans,f[x][y]+i.t+j.t);
			}
		}
		printf("%lld\n",ans+w[s]+w[t]);
	}
	return 0;
} 
