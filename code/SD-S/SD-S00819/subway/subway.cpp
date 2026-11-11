#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
const int N=509;
ll read(){
	ll x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1ll;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
ll c,n,m,d,q;
ll w[N];
ll k;
ll f[N][N];
int fa[N];
void solve1(){
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++){
		k=read();
		ll a[N],t[N];
		for(int j=1;j<=k;j++){
			a[j]=read(),t[j]=read();
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				f[a[j]][a[l]]=min(f[a[j]][a[l]],t[j]+t[l]);
			}
		}
	}
	for(int l=1;l<=m;l++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=min(f[i][j],f[i][l]+f[l][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int a=read(),b=read();
		cout<<f[a][b]+w[a]+w[b]<<endl;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	if(m<=500){
		solve1();
		return 0;
	}
	return 0;
}

