#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define pii pair<int,int>
#define fr first
#define sc second
#define ptc putchar
#define gtc getchar
using namespace std;
ll read(){
	ll x=0,f=1; char ch=gtc();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=gtc(); }
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gtc();
	return x*f;
}
void write(ll x){
	if(x<0) ptc('-'),x=-x;
	if(x>9) write(x/10);
	ptc(x%10+'0');
}
inline void printsp(ll x){ write(x),ptc(' '); }
inline void println(ll x){ write(x),ptc('\n'); }
const int maxn=5e5+5;
int n,m,d,q,w[maxn],pine[maxn][22],tim[maxn][22],acr[maxn];
ll f[505][505];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	int c_Test=read();
	n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int id=read(),t=read();
			pine[id][++acr[id]]=i;
			tim[id][acr[id]]=t;	
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j1=1;j1<=acr[i];j1++){
			for(int j2=j1+1;j2<=acr[i];j2++){
				int u1=pine[i][j1],u2=pine[i][j2];
				f[u1][u2]=min(f[u1][u2],(ll)tim[i][j1]+tim[i][j2]);
				f[u2][u1]=min(f[u2][u1],(ll)tim[i][j1]+tim[i][j2]);
			}
		}
	}
	for(int j=1;j<=n;j++)
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				f[j][k]=min(f[j][i]+f[i][k],f[j][k]);
	while(q--){
		int xr=read(),yr=read();
		ll ans=f[0][0];//max val
		for(int i=1;i<=acr[xr];i++){
			for(int j=1;j<=acr[yr];j++){
				ans=min(ans,tim[xr][i]+tim[yr][j]+f[pine[xr][i]][pine[yr][j]]);
			}
		}
		println(ans+w[xr]+w[yr]);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
