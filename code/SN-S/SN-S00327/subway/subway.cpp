//孟楚程  西安辅轮中学  SN-S00327 
#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int buflen=1<<22,maxm=4e5+5,maxn=505;
int pos,len,c,n,m,d,r,w[maxm],t[maxn][maxm];char buf[buflen];//t[i][j]表示第i个线路 第j个站的时间 
vector<int>bei[maxm];
vector<pair<int,int>>vc[maxm];//第一个表示线路  第二个表示站 
struct node{
	int u,w,z,com;//表示站  时间  线路 
};
queue<node>q;
char gc(){
	if(pos==len) len=fread(buf,1,buflen,stdin),pos=0;
	return pos==len?EOF:buf[pos++];
}
int rad(){
	int x=0,f=1;char ch=gc();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;if(ch==EOF) return 0;ch=gc();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=gc();}return x*f;
}
int bfs(int st,int ed){
	while(!q.empty()) q.pop();int ans=inf;
	for(int i:bei[st]) q.push({st,t[i][st],i,0});
	while(!q.empty()){
		auto xie=q.front();q.pop();int u=xie.u,nw=xie.w,z=xie.z,com=xie.com;
		if(u==ed){ans=min(ans,nw+t[z][u]);continue;}
		for(auto mcc:vc[u])if(mcc.second!=com){
			int xl=mcc.first,v=mcc.second;
			if(xl==z) q.push({v,nw,xl,u});
			else q.push({v,nw+t[z][u]+t[xl][u],xl,u});
		}
	}
	return ans;
}
signed main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	c=rad(),n=rad(),m=rad(),d=rad(),r=rad();
	//分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及计划数 
	for(int i=1;i<=m;i++) w[i]=rad();
	for(int i=1;i<=n;i++){
		int k=rad();int lst;
		for(int j=1;j<=k;j++){
			int a=rad(),tim=rad();t[i][a]=tim;bei[a].push_back(i);
			if(j!=1){vc[a].push_back({i,lst});vc[lst].push_back({i,a});}lst=a;
		}
	}
	for(int i=1;i<=r;i++){
		int sta=rad(),end=rad();
		cout<<bfs(sta,end)+w[sta]+w[end]<<'\n';
	}
	return 0;
}
