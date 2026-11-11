#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long read() {
	long long f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
void write(long long x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9) {
		write(x/10);
	}
	putchar(x%10+'0');
	return;
}
long long c,m,n,d,q,a[N],st,en;
long long head[N],l;
bool bo[N];
long long jsjs;
struct node {
	long long bh,lc,next;
} edge[N];
void add(long long x,long long y,long long z) {
	edge[++l].bh=y;
	edge[l].lc=z;
	edge[l].next=head[x];
	head[x]=l;
	return;
}
long long zdhead[N],lzd;
struct zdnode {
	long long bh,lc,next;
} zdedge[N];
void zdadd(long long x,long long y,long long z) {
	zdedge[++lzd].bh=y;
	zdedge[lzd].lc=z;
	zdedge[lzd].next=zdhead[x];
	zdhead[x]=lzd;
	return;
}
long long dis[N];
bool bobo[N];
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > p;
struct as {
	long long stt,enn,bh,anss;
} ass[N];
bool cmp(as x,as y) {
	return x.stt<y.stt;
}
bool cmp1(as x,as y) {
	return x.bh<y.bh;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1; i<=m; i++) a[i]=read();
	for(int i=1; i<=n; i++) {
		long long k=read();
		for(int j=1; j<=k; j++) {
			long long x=read(),y=read();
			add(i,x,y);
			zdadd(x,i,y);
		}
	}
	ass[0].stt=-2e16;
	for(int ii=1; ii<=q; ii++) {
		ass[ii].stt=read(),ass[ii].enn=read(),ass[ii].bh=ii;
		if(ass[ii].enn>ass[ii].stt) swap(ass[ii].enn,ass[ii].stt);
	}
	sort(ass+1,ass+1+q,cmp);
	for(int ii=1; ii<=q; ii++) {
		jsjs=0;
		st=ass[ii].stt,en=ass[ii].enn;
		if(ass[ii].stt!=ass[ii-1].stt) {
			for(int i=1; i<=m; i++) dis[i]=2e16,bo[i]=0;
			for(int i=1; i<=n; i++) bobo[i]=0;
			dis[st]=0;
			while(p.size()) p.pop();
			long long dq;
			p.push(make_pair(0,st));
			for(int i=1; i<=m; i++) {
				if(jsjs==n) break;
				if(p.size()==0) break;
				dq=p.top().second;
				p.pop();
				bo[dq]=1;
				for(int j=zdhead[dq]; j; j=zdedge[j].next) {
					if(bobo[zdedge[j].bh]==0) {
						bobo[zdedge[j].bh]=1;
						jsjs++;
						for(int q=head[zdedge[j].bh]; q; q=edge[q].next) {
							if(bo[edge[q].bh]==0) {
								if(dis[edge[q].bh]>dis[dq]+zdedge[j].lc+edge[q].lc) {
									dis[edge[q].bh]=dis[dq]+zdedge[j].lc+edge[q].lc;
									p.push(make_pair(dis[edge[q].bh],edge[q].bh));
								}
							}
						}
					}
				}
				while(p.size()&&bo[p.top().second]==1) p.pop();
			}
		}
		ass[ii].anss=dis[en]+a[st]+a[en];
	}
	sort(ass+1,ass+1+q,cmp1);
	for(int i=1; i<=q; i++) {
		write(ass[i].anss);
		putchar('\n');
	}
	return 0;
}
