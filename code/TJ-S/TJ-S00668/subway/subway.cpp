#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,hd[500005],cnt,dd;
long long dtk[505005],f[505005];
bool vst[505005],hs[505005],is[505005];
struct bian{
	long long t,next,v;
}e[2005005];
void add(long long f,long long t,long long v){
	++cnt;
	e[cnt].t=t;
	e[cnt].next=hd[f];
	e[cnt].v=v;
	hd[f]=cnt;
}
struct qee{
	long long v,nw;
	bool operator<(const qee & x)const{
		if(v!=x.v)return x.v<v;
		return x.nw>nw;
	}
};
priority_queue<qee> qe;
void djs(long long nw){
	qe.push({0,nw});
	vst[nw]=1;
	f[nw]=0; 
	while(qe.size()){
		long long nb=qe.top().nw,vu=qe.top().v;
		qe.pop();
		for(long long i=hd[nb];i;i=e[i].next){
			long long y=e[i].t;
			if(!vst[y]){
				vst[y]=1;
				f[y]=vu+e[i].v;
				qe.push({f[y],y});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>dtk[i];
	}
	dd=m;
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		long long ft=0,sd,upf;
		long long zt=++dd;
		is[dd]=1;
		for(long long j=1;j<=k;j++){
			long long ft,sd;
			cin>>ft>>sd;
			if(hs[ft]){
				add(ft,zt,sd);
				add(zt,ft,sd);
				ft=++dd;
			}
			else{
				add(ft,zt,sd);
				add(zt,ft,sd);
			}
			hs[ft]=1;
			upf=ft;
			if(j!=1){
				add(ft,upf,0);
				add(upf,ft,0);
			}
		}
	}
	for(long long i=1;i<=q;i++){
		long long fm,t;
		cin>>fm>>t;
		memset(vst,0,sizeof(vst));
		djs(fm);
		cout<<f[t]+dtk[t]+dtk[fm]<<"\n";
	}
	return 0;
}
