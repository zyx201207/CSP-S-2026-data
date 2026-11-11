//cam mik mut gi gwo
//seoi bun ngo cong dong
//kei mong bou jyu piu heoi
//bin wui cung po ming waan hun so
#include<bits/stdc++.h>
using namespace std;
char ib[1<<25],*ip1=ib,*ip2=ib;
inline char gc(){
	return ((ip1==ip2)&&(ip2=(ip1=ib)+fread(ib,1,1<<25,stdin)),(ip1==ip2?EOF:*ip1++));
}
inline int read(){//>=0
	int x=0;char c=gc();
	while(c<'0'||c>'9')c=gc();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^'0'),c=gc();
	return x;
}
int te,T,n,k;
//2<=k<=1e6,sum n<=2e6,1<=T<=5
const int N=1000005;
int d,hd[N],nxt[2*N],dy[2*N],t1=0;
inline void adde(int u,int v){
	nxt[++t1]=hd[u];hd[u]=t1,dy[t1]=v;
}
struct apple{
	int rt,dep[N],md[N],dm[N],d2[N],fa[N],sn[N];//0-index
	void dfs0(int x,int la){
		md[x]=sn[x]=0;
		for(int i=hd[x];i;i=nxt[i]){
			int cu=dy[i];
			if(cu==la)continue;
			dep[cu]=dep[x]+1;fa[cu]=x;dfs0(cu,x);
			if(md[x]<md[cu]+1)md[x]=md[cu]+1,sn[x]=cu;
		}
	}
	void dfs00(int x,int la){
		int m1=dm[x],m2=0,m3=0,m4=0;
		for(int i=hd[x];i;i=nxt[i]){
			int cu=dy[i];
			if(cu==la)continue;
			int z=md[cu]+1;
			if(m1<z)m2=m1,m1=z;
			else if(m2<z)m2=z;
			if(m3<z)m4=m3,m3=z;
			else if(m4<z)m4=z;
		}
		for(int i=hd[x];i;i=nxt[i]){
			int cu=dy[i];
			if(cu==la)continue;
			int z=md[cu]+1;
			if(z==m1)dm[cu]=1+m2;
			else dm[cu]=1+m1;
			d2[cu]=(z==m3?m4:m3);
			dfs00(cu,x);
		}
	}
	int fm[N],*f[N],t2;
	void dfs01(int x,int la){
		int y=sn[x];
		if(!y)return;
		f[y]=f[x]+1;dfs01(y,x);
		for(int i=hd[x];i;i=nxt[i]){
			int cu=dy[i];
			if(cu==la||cu==y)continue;
			f[cu]=fm+t2;t2+=md[cu];dfs01(cu,x);
		}
	}
	int f1[N],f2[N],f3[N];
	void dfs1(int x,int la){
		f1[x]=1;
		for(int i=hd[x];i;i=nxt[i]){
			int cu=dy[i];
			if(cu==la)continue;
			dfs1(cu,x);
			if(md[cu]+1>d)f1[x]+=f1[cu];
		}
	}
	void dfs2(int x,int la){
		if(dm[x]<=d)f2[x]=1;
		int he=f2[x];
		for(int i=hd[x];i;i=nxt[i]){
			int cu=dy[i];
			if(cu==la)continue;
			if(md[cu]+1>d)he+=f1[cu];
		}
		for(int i=hd[x];i;i=nxt[i]){
			int cu=dy[i];
			if(cu==la)continue;
			f2[cu]=he-(md[cu]+1>d?f1[cu]:0)+1;
			f3[cu]=(dm[cu]<=d?1:f2[cu]-1);
			dfs2(cu,x);
		}
	}
	void init(int rr){
		rt=rr;
		dep[rt]=0;fa[rt]=0;dfs0(rt,0);
		dm[rt]=0;d2[rt]=0;dfs00(rt,0);
		f[rt]=fm,t2=md[rt]+1;dfs01(rt,0);
	}
	int p[N],d1[N];bool ok;
	int d0[N];
	void dfs3(int x,int la){
		p[dep[x]]=x;
		for(int i=hd[x];i;i=nxt[i]){
			int cu=dy[i];
			if(cu==la)continue;
			d0[cu]=max(d0[x],dep[cu]-max(0,d-d2[cu]));
			d1[cu]=(d0[cu]==dep[cu]?cu:p[d0[cu]]);
			dfs3(cu,x);
		}
	}
	int dx[N];
	void dfs4(int x,int la){
		dx[x]=0;
		int y=sn[x];
		if(!y)return;
		dfs4(y,x);dx[x]=dx[y]+1;
		f[x][0]=min(f[x][0],f1[x]);
		//fm??+f3[d1[x]]<=k
		for(int i=hd[x];i;i=nxt[i]){
			int cu=dy[i];
			if(cu==la||cu==y)continue;
			dfs4(cu,x);
			for(int i=0;i<=dx[cu];++i){
				f[x][1+i]=min(f[x][1+i],f[cu][i]);
			}
			dx[x]=max(dx[x],dx[cu]+1);
		}
		if(x==rt)return;
		while(dx[x]>=0&&(la==rt||dx[x]+1+d2[x]>d)){
			if(f3[d1[x]]+f[x][dx[x]]<=k){
				ok=1;
			}
			f[x][dx[x]]=1e9;--dx[x];
		}
		//d2[x]+>d
	}
	bool check(){
		dfs1(rt,0);
		for(int i=1;i<=n;++i){
			if(dm[i]<=d&&f1[i]<=k)return 1;
			f2[i]=f3[i]=0;
		}
		dfs2(rt,0);
		ok=0;d0[rt]=1;dfs3(rt,0);
		for(int i=0;i<=n+2;++i)fm[i]=1e9;
		dfs4(rt,0);
		return ok;
	}
}s1,s2;
bool check(int mid){
	d=mid;
	if(s1.check())return 1;
	if(s2.check())return 1;
	return 0;
}
int dep[N];
void dfs_1(int x,int la){
	for(int i=hd[x];i;i=nxt[i]){
		int cu=dy[i];
		if(cu==la)continue;
		dep[cu]=dep[x]+1;
		dfs_1(cu,x);
	}
}
int main(){
	//duoce qingkong!!!
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	te=read(),T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;++i)hd[i]=0;
		for(int i=1;i<=t1;++i)nxt[i]=dy[i]=0;
		t1=0;
		for(int i=1;i<n;++i){
			int u=read(),v=read();
			adde(u,v);adde(v,u);
		}
		if(k==n){
			puts("0");continue;
		}
		dep[1]=0;dfs_1(1,0);
		int a=0,b=0;
		for(int i=1;i<=n;++i)if(!a||dep[a]<dep[i])a=i;
		dep[a]=0;dfs_1(a,0);
		for(int i=1;i<=n;++i)if(!b||dep[b]<dep[i])b=i;
		s1.init(a);s2.init(b);
		int L=1,R=n-k;
		while(L<=R){
			int mid=(L+R)>>1;
			if(check(mid))R=mid-1;
			else L=mid+1;
		}
		printf("%d\n",L);
	}
	return 0;
}
