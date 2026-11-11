#include<bits/stdc++.h>
using namespace std;
int c,n,m,dd,q;
long long w[20001],l,r,k[501],d[2001],v[2001],x[1001],y[1001];
struct jj{
	long long v,w,id;
	bool operator<(const jj &x)const{
		return w<x.w;}
};
vector<jj> a[20001],b[2001],t[2001];
priority_queue<jj> p;
long long read(){
	char ch=getchar();
	long long f=1,a=0;
	while(ch!='-'&&(ch<'0'||ch>'9'))
		ch=getchar();
	if(ch=='-'){
		f=-1;
		ch=getchar();}
	while(ch>='0'&&ch<='9'){
		a=a*10+(ch-'0');
		ch=getchar();}
	return a*f;}
int main(){
	freopen("subway4.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%lld%lld",&x[j],&y[j]);
		if(c<7||c>11){
			for(int j=1;j<=k[i];j++){
				a[x[j]].push_back((jj){i+m,y[j],0});
				a[i+m].push_back((jj){x[j],y[j],0});}
		}else{
			b[x[1]].push_back((jj){x[2],y[1]+y[2],0});
			b[x[2]].push_back((jj){x[1],y[1]+y[2],0});}
	}
	if(c>=7&&c<=11){
		while(q--){
			l=read();
			r=read();
			p.push((jj){l,0,0});
			for(int i=1;i<=505;i++){
				d[i]=5000000000000000;
				v[i]=0;}
			d[l]=0;
			while(!p.empty()){
				jj z=p.top();
				p.pop();
				if(v[z.v])
					continue;
				v[l]=1;
				v[z.v]=1;
				for(int j=0;j<b[z.v].size();j++){
					int nx=b[z.v][j].v,ny=b[z.v][j].w;
					if(d[nx]>d[z.v]+ny){
						d[nx]=d[z.v]+ny;
						p.push((jj){nx,d[nx],0});}
				}
			}
			printf("%lld\n",d[r]+w[l]+w[r]);}
	}else{
		while(q--){
			l=read();
			r=read();
			p.push((jj){l,0,0});
			for(int i=1;i<=2000;i++){
				d[i]=5000000000000000;
				v[i]=0;}
			d[l]=0;
			while(!p.empty()){
				jj z=p.top();
				p.pop();
				if(v[z.v])
					continue;
				v[l]=1;
				v[z.v]=1;
				for(int j=0;j<a[z.v].size();j++){
					int nx=a[z.v][j].v,ny=a[z.v][j].w;
					if(d[nx]>d[z.v]+ny){
						d[nx]=d[z.v]+ny;
						p.push((jj){nx,d[nx]});}
				}
			}
			printf("%lld\n",d[r]+w[l]+w[r]);}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
