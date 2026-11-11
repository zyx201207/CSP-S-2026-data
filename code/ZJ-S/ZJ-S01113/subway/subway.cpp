#include <bits/stdc++.h>
using namespace std;
void fre(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
long long c,n,m,d,q,ttt,kdz[500010],k[510],ans;
struct jgz{
	long long zhan,time;
};
struct jgx{
	long long xian,shun;
};
struct dui{
	long long qx,qxs,time,wz;
};
vector <jgz> g[510];
vector <jgx> h[500010];
long long v[500010];
queue <dui> qp;
void pian12b(long long x,long long y){
	dui dang;
	dang.qx=-1;
	dang.qxs=0;
	dang.time=kdz[x]+kdz[y];
	dang.wz=x;
	v[x]=dang.time;
	qp.push(dang);
	while(!qp.empty()){
		dui dang=qp.front();
		qp.pop();
		dui wei;
		for(int i=0;i<h[dang.wz].size();i++){
			wei.time=dang.time;
			jgx zan=h[dang.wz][i];
			if(dang.qx==-1){
				wei.qx=zan.xian;
				wei.qxs=zan.shun;
				if(zan.shun!=k[zan.xian]){
					wei.wz=g[zan.xian][zan.shun+1].zhan;
					wei.time++;
					if(wei.time<v[wei.wz]){
						v[wei.wz]=wei.time;
						qp.push(wei);
					}
				}
			}
			else{
				if(wei.qx!=zan.xian){
					wei.qx=zan.xian;
					wei.qxs=zan.shun;
					if(zan.shun!=k[zan.xian]){
						wei.wz=g[zan.xian][zan.shun+1].zhan;
						wei.time+=2;
						if(wei.time<v[wei.wz]){
							v[wei.wz]=wei.time;
							qp.push(wei);
						}
					}
				}
				else{
					if(zan.shun!=k[zan.xian]){
						wei.qxs=zan.shun;
						wei.wz=g[zan.xian][zan.shun+1].zhan;
						if(wei.time<v[wei.wz]){
							v[wei.wz]=wei.time;
							qp.push(wei);
						}
					}
				}
			}
		}
	}
	printf("%lld\n",((v[y]-(kdz[x]+kdz[y]))*ttt+(kdz[x]+kdz[y])));
}
void pian12(){
	long long x,y;
	for(int i=1;i<=q;i++){
		scanf("%lld %lld",&x,&y);
		memset(v,0x3fff,sizeof(v));
		pian12b(x,y);
	}
}
void bfs(long long x,long long y){
	dui dang;
	dang.qx=-1;
	dang.qxs=0;
	dang.time=kdz[x]+kdz[y];
	dang.wz=x;
	v[x]=dang.time;
	qp.push(dang);
	while(!qp.empty()){
		dui dang=qp.front();
		qp.pop();
		dui wei;
		cout<<dang.wz<<"\n";
		for(int i=0;i<h[dang.wz].size();i++){
			wei.time=dang.time;
			jgx zan=h[dang.wz][i];
			if(dang.qx==-1){
				wei.qx=zan.xian;
				wei.qxs=zan.shun;
				if(zan.shun!=k[zan.xian]){
					wei.wz=g[zan.xian][zan.shun+1].zhan;
					wei.time+=g[zan.xian][zan.shun].time;
					if(wei.time<v[wei.wz]){
						v[wei.wz]=wei.time;
						qp.push(wei);
					}
				}
			}
			else{
				if(wei.qx!=zan.xian){
					wei.qx=zan.xian;
					wei.qxs=zan.shun;
					if(zan.shun!=k[zan.xian]){
						wei.wz=g[zan.xian][zan.shun+1].zhan;
						wei.time+=g[zan.xian][zan.shun].time+g[wei.qx][wei.qxs].time;
						if(wei.time<v[wei.wz]){
							v[wei.wz]=wei.time;
							qp.push(wei);
						}
					}
				}
				else{
					if(zan.shun!=k[zan.xian]){
						wei.qxs=zan.shun;
						wei.wz=g[zan.xian][zan.shun+1].zhan;
						if(wei.time<v[wei.wz]){
							v[wei.wz]=wei.time;
							qp.push(wei);
						}
					}
				}
			}
		}
	}
	printf("%lld\n",&v[y]);
}
int main(){
	fre();
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&kdz[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			jgz oo;
			scanf("%lld %lld",&oo.zhan,&oo.time);
			ttt=oo.time;
			g[i].push_back(oo);
			jgx ooo;
			ooo.xian=i;
			ooo.shun=j-1;
			h[oo.zhan].push_back(ooo);
		}
	}
	if(12<=c&&c<=19){
		pian12();
	}
	long long x,y;
	for(int i=1;i<=q;i++){
		scanf("%lld %lld",&x,&y);
		memset(v,0x3fff,sizeof(v));
		bfs(x,y);
	}
	return 0;
}
