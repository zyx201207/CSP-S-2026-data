#include<bits/stdc++.h>
#define FOR(i,s,e) for(int i=s;i<=e;++i)
#define ROF(i,e,s) for(int i=e;i>=s;--i)
#define LL long long
using namespace std;
const int N=205;
const int M=2e4+5;
inline int read(){
	int x=0,f=1;
	char s=getchar();
	while(s<'0'||s>'9'){ if(s=='-') f=-1;s=getchar(); }
	while(s>='0'&&s<='9'){ x=x*10+(s-'0'); s=getchar(); }
	return x*f;
}
int c,n,m,d,q;
int pss[N];
vector<int> ps[N];
LL w[M],ans,k[N],a[N][M],t[N][M];
LL f[N][N];//f[i][j]表示从第i条线换到第j条线所用的最少步行时间 初始值全都设为0x3f3f3f3f(正无穷) 
bool vis[M][25];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f3f3f3f,sizeof f);
	c=read();n=read();m=read();d=read();q=read();
	FOR(i,1,m){
		w[i]=read();
	}
	FOR(i,1,n)
		f[i][i]=0;
	FOR(i,1,n){
		k[i]=read();
		FOR(j,1,k[i]){
			a[i][j]=read();
			t[i][a[i][j]]=read();
			vis[a[i][j]][i]=1;
			pss[a[i][j]]++;
			for(int k:ps[a[i][j]]){
				f[k][i]=min(f[k][i],t[k][a[i][j]]+t[i][a[i][j]]);
				f[i][k]=min(f[i][k],t[k][a[i][j]]+t[i][a[i][j]]);
			}
			ps[a[i][j]].push_back(i);
		}
	}
	FOR(k,1,n){
		FOR(i,1,n){
			FOR(j,1,n){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	FOR(k,1,q){
		int x,y;
		x=read();y=read();
		ans=1e18;
		for(int i:ps[x]){
			for(int j:ps[y]){
				ans=min(ans,t[i][x]+t[j][y]+f[i][j]);
			}
		}
		ans=ans+w[x]+w[y];
		cout << ans << endl;
	}
	return 0;
}
//对于每个x,y所处于的线路 一一枚举他们之间所有的时间(最小转乘时间+步行到x,y的时间+从站厅到该线的时间) 最小值即为答案 

