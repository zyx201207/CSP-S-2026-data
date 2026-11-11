#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define FOR(i,x,y) for(int i=(x);i<=(y);i++)
#define ROF(i,x,y) for(int i=(x);i>=(y);i--)
#define EDGE(i,u) for(int i=head[u];~i;i=e[i].nxt)
#define INF 0x3f3f3f3f3f3f3f3f
#define pb push_back 
#define fi first
#define se second
int read(){
	int k=0,f=1;char c=getchar();
	while(c<'0' or c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' and c<='9'){
		k=k*10+c-'0';c=getchar();
	}
	return k*f;
}
void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	else print(x/10),putchar(x%10+'0');
}

const int N=500+5;
const int M=5e5+5;

// Oct31==Dec25?
//16:06

vector<pair<int,int>> liss[M];

int w[M],dis[N][N];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	FOR(i,1,m) w[i]=read();
	//cout<<"???\n";
	FOR(i,1,n){
		int k=read();
		FOR(j,1,k){
			int st=read(),ti=read();
			liss[st].pb({i,ti});
		}
	}
	
	memset(dis,0x3f,sizeof dis);
	
	FOR(k,1,m){
		FOR(i,0,liss[k].size()-1){
			dis[liss[k][i].fi][liss[k][i].fi]=0;
			FOR(j,0,liss[k].size()-1){
				dis[liss[k][i].fi][liss[k][j].fi]=min(dis[liss[k][i].fi][liss[k][j].fi],liss[k][i].se+liss[k][j].se);
			}
		}
	}
	
	FOR(k,1,n) FOR(i,1,n) FOR(j,1,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	
	while(q--){
		int x=read(),y=read();
		int ans=INF;
		FOR(i,0,liss[x].size()-1) FOR(j,0,liss[y].size()-1){
			ans=min(ans,dis[liss[x][i].fi][liss[y][j].fi]+w[x]+w[y]+liss[x][i].se+liss[y][j].se);
		}
		print(ans),putchar('\n');
	}
	
	return 0;
} 
