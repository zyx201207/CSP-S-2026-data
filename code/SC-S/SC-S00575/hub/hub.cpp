#include<bits/stdc++.h>
using namespace std;
const int N=1e3+9,KK=30+9;
const int MAXN=1e9+7; 
int c,T;
int n,k,L,ans;
vector<int> e[N];
int fa[N][KK],_in[N],_out[N],tim,dep[N];
int val[N][N];
bool vis[N];
void _invit(){
	ans=MAXN;tim=0;
	for(int i=1;i<=n;i++) e[i].clear(),_in[i]=_out[i]=dep[i]=0; 
	for(int i=1;i<=n;i++) for(int j=1;j<=L;j++) fa[i][j]=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) val[i][j]=0;
}
void dfs(int x,int y){
	fa[x][0]=y;dep[x]=dep[y]+1;_in[x]=++tim;
	for(int i=1;i<=L;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(auto v:e[x]) if(v!=y) dfs(v,x);
	_out[x]=++tim;
}
bool check_fa(int x,int y){
	return (_in[x]<=_in[y])&&(_out[x]>=_out[y]);
}
int lca(int x,int y){
	if(check_fa(x,y)) return x;
	if(check_fa(y,x)) return y;
	for(int i=L;i>=0;i--) if(!check_fa(fa[x][i],y)) x=fa[x][i];
	return fa[x][0];
}
int dis(int x,int y){
	int d=lca(x,y);
	return dep[x]+dep[y]-dep[d]*2;
}
int find_fa(int x,int step){
	for(int i=L;i>=0;i--) if((1<<i)<=step)
		step-=(1<<i),x=fa[x][i];
	return x;
}
bool check(int tag,int s1,int s2){
	for(int i=1;i<=n;i++) vis[i]=false;
	vis[s1]=vis[s2]=true;
	for(int i=1;i<=n;i++){
		int now=min(val[s1][i],val[s2][i]);
		if(now>tag){
			if(!check_fa(s1,i)&&!check_fa(s2,i)) return false;
			else{
				int up=-1;
				if(check_fa(s1,i)&&check_fa(s2,i)) up=min(val[s1][i]-tag,val[s2][i]-tag);
				else if(check_fa(s1,i)) up=val[s1][i]-tag;
				else if(check_fa(s2,i)) up=val[s2][i]-tag;
				int ss=find_fa(i,up);
				while(!vis[ss]) vis[ss]=true,ss=fa[ss][0];	
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++) if(vis[i]) cnt++;
	return (cnt<=k);
}
int find_ans(int l,int r,int s1,int s2){
	if(l==r) return l;
	int mid=(l+r)/2;
	if(check(mid,s1,s2)) return find_ans(l,mid,s1,s2);
	else return find_ans(mid+1,r,s1,s2);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		_invit();
		scanf("%d%d",&n,&k);L=ceil(log2(n));
		for(int i=1,sx,sy;i<n;i++){
			scanf("%d%d",&sx,&sy);
			e[sx].push_back(sy);
			e[sy].push_back(sx);
		}
		if(k==n){ printf("0\n");continue; }
		dfs(1,1);
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) val[i][j]=dis(i,j);
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
			ans=min(ans,find_ans(1,n,i,j));
		}
		printf("%d\n",ans);
	}
	return 0;
} 