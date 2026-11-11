#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
long long lread(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
vector<int>ct[1000001];
int b,c;
queue<int>q;
int zd;
int zs[1000001];
int fa[1000001];
int fjl[1000001];
void dfs1(const int w,const int f){
	zs[w]=0;
	fa[w]=f;
	for(int v:ct[w]){
		if(v!=f){
			dfs1(v,w);
			zs[w]=max(zs[w],zs[v]+1);
		}
	}
	return;
}
void dfs2(const int w,const int f){
	int zc(0);
	for(int v:ct[w]){
		if(v!=f){
			if(zs[v]>=zs[zc])zc=v;
		}
	}
	for(int v:ct[w]){
		if(v!=f){
			fjl[v]=fjl[w]+1;
			if(v==zc){
				for(int var:ct[w]){
					if(var!=v)fjl[v]=max(fjl[v],zs[var]+2);
				}
			}
			else{
				fjl[v]=max(fjl[v],zs[w]+1);
			}
			dfs2(v,w);
		}
	}
	return;
}
int rd[1000001];
bool bj[1000001];
bool bj2[1000001];
int cl[1000001];
int gs[1000001];
int jl[1000001];
int cl2[1000001];
int bz[1000001][21];
void dfs3(const int w,const int f){
	bz[w][0]=f;
	for(int v=0;;++v){
		bz[w][v]=bz[bz[w][v-1]][v-1];
		if(bz[w][v]==0)break;
	}
	bj2[w]=bj[w];
	for(int v:ct[w]){
		if(v!=f){
			dfs3(v,w);
			bj2[w]=bj2[w]|bj2[v];
		}
	}
	return;
}
void dfs4(const int w,const int f){
	if(bj[w]){
		cl[w]=0;
	}
	else{
		cl[w]=1145141919;
	}
	for(int v:ct[w]){
		if(v!=f&&bj2[v]){
			dfs4(v,w);
			if(cl[w]==1145141919){
				cl[w]=cl[v]+1;
			}
			else{
				cl[w]=0;
			}
		}
	}
	return;
}
bool ck(const int a){
	int d,e(0);
	for(int v=1;v<=b;++v){
		d=fjl[v];
		for(int var:ct[v]){
			if(var!=fa[v]){
				d=min(d,zs[var]+1);
			}
		}
		if(d>=a)++e;
	}
	if(e<=c){
		return true;
	}
	for(int v=1;v<=b;++v){
		rd[v]=0;
		bj[v]=0;
		jl[v]=0;
		cl2[v]=0;
	}
	for(int v=1;v<=b;++v){
		for(int var:ct[v]){
			++rd[var];
		}
	}
	for(int v=1;v<=b;++v){
		if(rd[v]==1){
			jl[v]=1;
			q.push(v);
		}
	}
	while(!q.empty()){
		d=q.front();
		q.pop();
		if(jl[d]>a){
			bj[d]=1;
			continue;
		}
		for(int v:ct[d]){
			--rd[v];
			if(rd[v]){
				if(jl[v]==0){
					jl[v]=jl[d]+1;
				}
				else{
					jl[v]=max(jl[v],jl[d]+1);
				}
			}
			if(rd[v]==1){
				q.push(v);
			}
		}
	}
	for(int v=1;v<=b;++v){
		if(jl[v]>a)bj[v]=1;
	}
	for(int v=1;v<=b;++v){
		if(bj[v]){
			d=v;
			break;
		}
	}
	dfs3(d,0);
	e=0;
	int f=0,g;
	for(int v=1;v<=b;++v){
		if(bj[v])++e;
		else if(bj2[v])f=v;
	}
	if(!f){
		return e<=c;
	}
	dfs4(d,0);
	for(int v=1;v<=b;++v){
		if(!bj[v]&&bj2[v]&&jl[v]){
			e=a-jl[v]+1;
			f=v;
			for(int var=0;e;++var){
				if(e&(1<<var)){
					e=e^(1<<var);
					f=bz[f][e];
				}
			}
			cl[f]=min(cl[f],(a-jl[v]+1)*2);
		}
	}
	e=0;
	d=0;
	for(int v=1;v<=b;++v){
		if(bj2[v]){
			d=max(d,cl[v]);
			++e;
		}
	}
	d=min(d,a*2);
	return e-d<=c;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int a,d,e,l,r,m;
	read();
	a=read();
	while(a--){
		b=read();
		c=read();
		for(int v=1;v<=b;++v){
			ct[v].clear();
		}
		for(int v=1;v<b;++v){
			d=read();
			e=read();
			ct[d].push_back(e);
			ct[e].push_back(d);
		}
//		if(a)continue;
		dfs1(1,0);
		fjl[1]=0;
		dfs2(1,0);
		l=0;
		r=b;
		while(l<r){
			m=(l+r>>1);
			if(ck(m)){
				r=m;
			}
			else{
				l=m+1;
			}
		}
		cout<<l<<'\n';
	}
	return 0;
} 