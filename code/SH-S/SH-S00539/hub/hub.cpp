#include <bits/stdc++.h>
char buf[1000009],*paa=buf,*pd=buf;
#define getchar() ((paa==pd)&&(paa=buf,pd=buf+fread(buf,1,1000000,stdin),paa==pd)?EOF:(*paa++))
inline int read() {
	char op=getchar();
	while(op<'0'||op>'9') {
		op=getchar();
	}
	int x=0;
	while(op>='0'&&op<='9') {
		x=x*10+op-'0';
		op=getchar();
	}
	return x;
}
int C,T,N,K,hd[1000009],to[2000009],nxt[2000009],ma[1000009],pa[1000009],
dep[1000009],zq[1000009],nd[1000009],fl,v,k,rt,son[1000009],su[1000009];
void l(int u,int v) {
	to[++k]=v;nxt[k]=hd[u];hd[u]=k;
}
struct n_t{
	int a,b;
};
void dfs(int n,int f) {
	ma[n]=0;pa[n]=f;dep[n]=dep[f]+1;
	for(int i=hd[n];i;i=nxt[i]) {
		if(to[i]==f) continue;
		dfs(to[i],n);
		ma[n]=std::max(ma[n],ma[to[i]]+1);
	}
}
void dfs2(int n,int f) {
	int a=0,b=0;
	for(int i=hd[n];i;i=nxt[i]) {
		if(to[i]==f) continue;
		if(b<ma[to[i]]+1) {
			a=b;b=ma[to[i]]+1;
		} else a=std::max(a,ma[to[i]]+1);
	}
	for(int i=hd[n];i;i=nxt[i]) {
		if(to[i]==f) continue;
		dfs2(to[i],n);
		if(b==ma[to[i]]+1) {
			zq[to[i]]=a;
		} else {
			zq[to[i]]=b;
		}
	}	
}
void dfs3(int n,int f) {
	su[n]=0;
	if(ma[n]>=v) su[n]=1;
	int cc=0,mm=0,ll;
	for(int i=hd[n];i;i=nxt[i]) {
		if(to[i]==f) continue;
		dfs3(to[i],n);
		if(ma[to[i]]>=v) cc++,ll=to[i];
		else mm=std::max(mm,ma[to[i]]+1);
		su[n]+=su[to[i]];
	}
	son[n]=0;
	if(ma[n]<=v) {
		nd[n]=n;
	} else {
		if(cc>=2) {
			nd[n]=n;
		} else {
			son[n]=ll;
			int x=nd[ll];
			while(dep[x]-dep[n]+mm>v) {
				x=pa[x];
			}
			nd[n]=x;
		}
	}
}
void dfs4(int n,int f,int ss,int s2) {
	if(ss+s2+std::max(1,su[nd[n]])<=K) {
//		printf("%d %d %d %d %d %d\n",v,n,ss,s2,nd[n],su[1]);
		fl=1;
		return;
	}
	for(int i=hd[n];i;i=nxt[i]) {
		if(to[i]==f) continue;
		int dt=dep[n]+1-std::max(v-zq[to[i]],0);
		dfs4(to[i],n,ss+su[n]-su[to[i]]-((ma[n]>=v)?1:0),std::max(s2,dt));
		if(fl) return;
	}
}
int t1[1000009],t2[1000009];
bool chk(int qqqqq) {
	v=qqqqq;
	fl=0;
	int aa=0;
	for(int i=1;i<=N;i++) {
		if(ma[i]>=v) {
			aa++;
		}
	}
	if(aa<=K) return 1;
	dfs3(rt,0);
	if(su[nd[rt]]<=K) return 1;
	dfs4(rt,0,0,0);
	if(fl) return 1;
	//if(v==1) printf("ee\n");
	std::vector<int> aq;
	std::vector<n_t> a1,a3;
	int as=0;
	for(int i=hd[rt];i;i=nxt[i]) {
		if(ma[to[i]]>=v) {
			aq.push_back(to[i]);
		} else as=std::max(as,ma[to[i]]+1);
	}
	if(aq.size()!=2) return 0;
	int x=aq[0],y=aq[1];
	while(x) {
		a1.push_back((n_t){x,zq[son[x]]});
		x=son[x];
	}
	for(int i=a1.size()-1;i>=0;i--) a3.push_back(a1[i]);
	a3.push_back((n_t){rt,as});
	while(y) {
		a3.push_back((n_t){y,zq[son[y]]});
		y=son[y];
	}
	int la=su[a3[0].a]+su[a3[a3.size()-1].a];
	for(int i=0;i<a3.size();i++) t2[i]=a3.size()-1;
	int ww=0;
	for(int i=0;i<a3.size();i++) {
		int n1=a3[i].b+i-v;
		ww=std::max(ww,n1);
		t1[i]=ww;
		int n2=v-a3[i].b+i;
		if(i) t2[i-1]=n2;
	}
//	printf("%d %d\n",la,v);
//	for(int i=0;i<a3.size();i++) printf("%d %d\n",a3[i].a,a3[i].b);
	for(int i=a3.size()-2;i>=0;i--) {
		t2[i]=std::min(t2[i],t2[i+1]);
	}
	for(int i=0;i+1<a3.size();i++) {
		if(la+t1[i]+a3.size()-t2[i]-1<=K) return 1;
	}	
/*	for(int i=0;i<a3.size();i++) {
		for(int j=i+1;j<a3.size();j++) {
			bool gg=0;
			for(int k=i+1;k<j;k++) {
				if(std::min(k-i,j-k)+a3[k].b>v) {
					gg=1;break;
				}
			}
			if((gg==0)&&(la+i+a3.size()-j-1<=K)) return 1;
		}
	}*/
	return 0;
}

signed main(void) {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	C=read();T=read();
//	scanf("%d %d",&C,&T);
	int cc=0;
	while(T--) {
		cc++;
		N=read();K=read();
//		scanf("%d %d",&N,&K);
		//if(cc==72677) printf("%d %d\n",N,K);
		for(int i=1;i<=N;i++) hd[i]=0;k=0;
		for(int i=1;i<N;i++) {
			int u=read(),v=read();
//			scanf("%d %d",&u,&v);
		//	if(cc==72677) printf("%d %d\n",u,v);
			l(u,v),l(v,u);
		}
	//	continue;
		if(K==N) {
			printf("0\n");
			continue;
		}
		dep[0]=-1;
		dfs(1,0);
		for(int i=1;i<=N;i++) {
			if(dep[i]==ma[1]) {
				rt=i;
				break;
			}
		}
		dfs(rt,0);
		int rt2;
		for(int i=1;i<=N;i++) {
			if(dep[i]==ma[rt]) {
				rt2=i;
				break;
			}
		}
		int le=dep[rt2]/2;
		for(int i=1;i<=le;i++) rt2=pa[rt2];
		rt=rt2;
		dfs(rt,0);
		dfs2(rt,0);
		//printf("!! %d\n",rt);
		int l=1,r=N,mm;
		while(l<r) {
			mm=(l+r)/2;
			if(chk(mm)) r=mm;else l=mm+1;
		}
		printf("%d\n",l);
	}
}
