#include<bits/stdc++.h>
#define int long long
#define N 55
#define M 500005
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
inline int read(){
	int seg=0,sgn=0;char ch;
	while(!isdigit(ch))sgn|=ch=='-',ch=getchar();
	while(isdigit(ch))seg=seg*10+ch-'0',ch=getchar();
	return sgn?-seg:seg;
}
int c,n,m,d,q;
int len[N];
struct subwayline{
	int id,otime;
}line[N][M];
struct station{
	int intime,linesum;
	int lineid,otime;
	bool istrans;
	int id[N];
	int s[N];
}sta[M];
int trans[N][N],fff[N][N];
bool vis[N][N];
struct node{
	int id,len;
};
inline int mindis(int i,int j){
	memset(vis,true,sizeof(vis));
	queue<node>Q;
	Q.push((node){i,0});
	int mi=fff[i][j];
	while(!Q.empty()){
		node tmp=Q.front();Q.pop();
		int now=tmp.id,nlen=tmp.len;
		if(now==j)mi=min(mi,nlen);
//		cout<<now<<':'<<nlen<<'\n';
		rep(k,1,n)
			if(k!=now&&vis[now][k]&&fff[now][k]!=0x3f3f3f){
				vis[now][k]=false;
				Q.push((node){k,nlen+fff[now][k]});
			}
	}
	return mi;
}
inline void work1(){
	memset(sta,0,sizeof(sta));
	memset(fff,0x3f3f3f,sizeof(fff));
	rep(i,1,m){
		sta[i].intime=read();
		sta[i].linesum=0;
		sta[i].istrans=false;
	}
	
	rep(i,1,n){
		len[i]=read();
		rep(j,1,len[i]){
			int id=read();
			line[i][j].id=id;
			line[i][j].otime=read();
			sta[id].linesum++;
			if(sta[id].linesum>1)sta[id].istrans=true;
		}
	}
	
	rep(i,1,n)rep(j,1,len[i]){
		int id=line[i][j].id;
		if(!sta[id].istrans){
			sta[id].lineid=i;
			sta[id].otime=line[i][j].otime;
		}
		else {
//			if(sta[id].id1==0)sta[id].id1=i,sta[id].s1=line[i][j].otime;
//			else sta[id].id2=i,sta[id].s2=line[i][j].otime;
			
			int k=1;
			while(sta[id].id[k]!=0)++k;
			sta[id].id[k]=i;
			sta[id].s[k]=line[i][j].otime;
		}
	}
	
	rep(i,1,m)
		if(sta[i].istrans)
			rep(j,1,sta[i].linesum)
			rep(k,j+1,sta[i].linesum)
			fff[sta[i].id[j]][sta[i].id[k]]=fff[sta[i].id[k]][sta[i].id[j]]=min(fff[sta[i].id[k]][sta[i].id[j]],sta[i].s[j]+sta[i].s[k]);
			
//	cout<<mindis(1,3)<<'\n';
	
	rep(i,1,n)rep(j,i+1,n)trans[i][j]=trans[j][i]=mindis(i,j);
			
//	rep(i,1,n){
//		rep(j,1,n)cout<<trans[i][j]<<' ';
//		cout<<'\n';
//	}
//	cout<<"AK\n";
	
	while(q--){
		int x=read(),y=read();
		int ans=sta[x].intime+sta[y].intime;
		int nx,ny,linex[N],liney[N],sx[N],sy[N];
		if(sta[x].istrans){
			nx=sta[x].linesum;
			rep(i,1,nx)linex[i]=sta[x].id[i],sx[i]=sta[x].s[i];
		}
		else {
			nx=1;
			linex[1]=sta[x].lineid;sx[1]=sta[x].otime;
		}
		if(sta[y].istrans){
			ny=sta[y].linesum;
			rep(i,1,ny)liney[i]=sta[y].id[i],sy[i]=sta[y].s[i];
		}
		else {
			ny=1;
			liney[1]=sta[y].lineid;sy[1]=sta[y].otime;
		}
		int ans2=LONG_LONG_MAX;
		rep(i,1,nx)
			rep(j,1,ny){
				int sum=trans[linex[i]][liney[j]]+sx[i]+sy[j];
				ans2=min(ans2,sum);
			}
		cout<<ans+ans2<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	mt19937 Rand(time(0));
	c=read();n=read();m=read();d=read();q=read();
//	if(c>=12&&c<=19)
	work1();
	return 0;
}
