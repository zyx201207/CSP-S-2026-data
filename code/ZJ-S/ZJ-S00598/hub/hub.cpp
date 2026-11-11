#include<bits/stdc++.h>
#define int long long
#define raed(x) read(x)
#define Spa putchar(' ')
#define Nxt puts("");
#define Pline puts("--------------")
namespace FastIO{
	int read_x,read_f,write_top;
	int write_st[25];
	char read_char;
	inline int read(int &x){
		x=0;
		read_f=1;
		read_char=getchar();
		while(!isdigit(read_char)){
			if(read_char=='-')read_f=-1;
			read_char=getchar();
		}
		while(isdigit(read_char)){
			x=(x<<1)+(x<<3)+(read_char-'0');
			read_char=getchar();
		}
		return x*=read_f;
	}
	inline int read(){
		read_x=0;
		read_f=1;
		read_char=getchar();
		while(!isdigit(read_char)){
			if(read_char=='-')read_f=-1;
			read_char=getchar();
		}
		while(isdigit(read_char)){
			read_x=(read_x<<1)+(read_x<<3)+(read_char-'0');
			read_char=getchar();
		}
		return read_x*read_f;
	}
	inline void write(int x){
		if(x<0)putchar('-'),x=-x;
		do{
			write_st[++write_top]=x%10;
			x/=10;
		}while(x);
		while(write_top)putchar(write_st[write_top--]+'0');
		return ;
	}
	inline void tomax(int &x,int y){
		if(x<y)x=y;
		return ;
	}
	inline void tomin(int &x,int y){
		if(x>y)x=y;
		return ;
	}
}
using namespace FastIO;
using namespace std;
int type;
namespace Subtask1{
const int N=105,inf=0x3f3f3f3f;
int n,k;
vector<int>e[N];

int D;
int cnt;
int mxdep[N];
void dfs3(int u,int fa,int locked){
	mxdep[u]=0;
	for(int v:e[u]){
		if(v==fa||v==locked)continue;
		dfs3(v,u,locked);
		tomax(mxdep[u],mxdep[v]+1);
	}
	if(fa==0||mxdep[u]>=D)cnt++;
}
void dfs2(int u,int fa,int locked,int &mi){
	cnt=0;
	dfs3(u,0,locked);
	tomin(mi,cnt);
//	cout<<u<<' '<<cnt<<endl;
	for(int v:e[u]){
		if(v==fa||v==locked)continue;
		dfs2(v,u,locked,mi);
	}
}
int mi;
void dfs1(int u,int fa){
	for(int v:e[u]){
		if(v==fa)continue;
		dfs1(v,u);
	}
	if(fa){
		//cut the edge of u and fa
		int mi1=inf,mi2=inf;
		dfs2(u,0,fa,mi1);
		dfs2(fa,0,u,mi2);
//		cout<<u<<' '<<fa<<' '<<mi1<<' '<<mi2<<endl;
		tomin(mi,mi1+mi2);
	}
}
bool check(int x){
	D=x,mi=inf;
	dfs1(1,0);
	return mi<=k;
}
void solve(){
	read(n),read(k);
	for(int i=1;i<=n;i++)
		e[i].clear();
	for(int i=2,u,v;i<=n;i++){
		read(u),read(v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
//	cerr<<check(1)<<endl;
	int l=1,r=n-1,res=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			res=mid;
			r=mid-1;
		}else l=mid+1;
	}
	write(res),Nxt;
}
}
namespace Subtask2{
#define pii pair<int,int>
const int N=1005,inf=0x3f3f3f3f;
int n,k;
vector<int>e[N];

int D;
int mxdep[N][2];
int mi,cnt;
void dfs2(int u,int fa,int locked){
//	cout<<u<<' '<<cnt<<endl;
	mxdep[u][0]=0;
	mxdep[u][1]=-inf;
	for(int v:e[u]){
		if(v==fa||v==locked)continue;
		dfs2(v,u,locked);
		if(mxdep[u][0]<mxdep[v][0]+1){
			mxdep[u][1]=mxdep[u][0];
			mxdep[u][0]=mxdep[v][0]+1;
		}else tomax(mxdep[u][1],mxdep[v][0]+1);
	}
	if(!fa||mxdep[u][0]>=D)cnt++;
}
void dfs3(int u,int fa,int locked,int &mi){
	tomin(mi,cnt);
	
	for(int v:e[u]){
		if(v==fa||v==locked)continue;
		cnt--;
		if(mxdep[v][0]>=D)cnt--;
		
		int tmpmxdep;
		pii tmp={mxdep[v][0],mxdep[v][1]};
		if(mxdep[v][0]+1==mxdep[u][0])tmpmxdep=mxdep[u][1];
		else tmpmxdep=mxdep[u][0];
		if(mxdep[v][0]<tmpmxdep+1){
			mxdep[v][1]=mxdep[v][0];
			mxdep[v][0]=tmpmxdep+1;
		}else tomax(mxdep[v][1],tmpmxdep+1);
		
		cnt++;
		if(tmpmxdep>=D)cnt++;
		
		dfs3(v,u,locked,mi);
		
		cnt--;
		if(tmpmxdep>=D)cnt--;
		
		mxdep[v][0]=tmp.first;
		mxdep[v][1]=tmp.second;
		
		cnt++;
		if(mxdep[v][0]>=D)cnt++;
	}
}
void dfs1(int u,int fa){
	for(int v:e[u]){
		if(v==fa)continue;
		dfs1(v,u);
	}
	if(fa){
		//cut the edge of u and fa
		int mi1=inf,mi2=inf;
		cnt=0;
		dfs2(u,0,fa);
		dfs3(u,0,fa,mi1);
		
		cnt=0;
		dfs2(fa,0,u);
		dfs3(fa,0,u,mi2);
//		cout<<u<<' '<<fa<<' '<<mi1<<' '<<mi2<<endl;
		tomin(mi,mi1+mi2);
	}
}
bool check(int x){
	D=x,mi=inf;
	dfs1(1,0);
	return mi<=k;
}
void solve(){
	read(n),read(k);
	for(int i=1;i<=n;i++)
		e[i].clear();
	for(int i=2,u,v;i<=n;i++){
		read(u),read(v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
//	cerr<<check(1)<<endl;
	int l=1,r=n-1,res=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			res=mid;
			r=mid-1;
		}else l=mid+1;
	}
	write(res),Nxt;	
}
#undef pii
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	read(type),read(t);
	while(t--){
		Subtask2::solve();
	}
}
/*
Binary sereach
choose an edge and cut it 
we need calcuate a mininum size for each block
choose a point and dfs from it
maybe n^3\log n
ok six points
the centre of the tree ?
we consider to change the root
when the root is changed from u to v,the mxdep just change u and v
and we can let the code from n^3\log n to n^2\log n
ten pts more right?oh yeah

ok let we consdier when the point is best
when we change the root from u to v
if at first the v isn't chosen
v must be chosen,the cnt add one
if u is still chosen,the cnt is bigger
if v isn't chosen any more,the cnt isn't changed
Obviously,it won't be the best

so the v must be chosen at first
and the u isn't chosen after the movement 
it means,we will go into the v that has max depth
it just like a centre of weight
and when we stop and delete the root,the max depth of subtree is smallest


*/
