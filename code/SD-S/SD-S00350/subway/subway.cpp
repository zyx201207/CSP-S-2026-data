#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define rop(i,a,b) for(int i=(a);i<(b);++i)
int iread(){int x=0,y=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-') y=-1;c=getchar();}while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}return x*y;}
ll lread(){ll x=0,y=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-') y=-1;c=getchar();}while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}return x*y;}
const int N=502;
const int M=5e5+2;
const int D=22;
int c,n,m,d,q;
int bj[M][D];
int w[M];
int t[N][M];
ll mp[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=iread();
	n=iread();
	m=iread();
	d=iread();
	q=iread();
	FOR(i,1,m) w[i]=iread();
	FOR(i,1,n){
		int k=iread();
		FOR(j,1,k){
			int a=iread();
			int tm=iread();
			t[i][a]=tm;
			bj[a][++bj[a][0]]=i;
		}
	}
	memset(mp,0x7f,sizeof mp);
	FOR(i,1,m){
		int up=bj[i][0];
		FOR(a,1,up){
			FOR(b,1,up){
				int x=bj[i][a];
				int y=bj[i][b];
				mp[x][y]=min(mp[x][y],0ll+t[x][i]+t[y][i]);
			}
		}
	}
	FOR(i,1,n) mp[i][i]=0;
	FOR(k,1,n){
		FOR(i,1,n){
			FOR(j,1,n){
				if(i==j||i==k||k==j) continue;
				if(mp[i][k]>1e18||mp[k][j]>1e18) continue;
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
	FOR(h,1,q){
		int x=iread();
		int y=iread();
		int a=bj[x][0],b=bj[y][0];
		ll ans=1e18;
		FOR(i,1,a){
			FOR(j,1,b){
				int st=bj[x][i],ed=bj[y][j];
				ans=min(ans,0ll+w[x]+w[y]+t[st][x]+t[ed][y]+mp[st][ed]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

