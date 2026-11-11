#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int ret=0;bool opt=0;char in=getchar();
	while(!isdigit(in)){opt|=(in=='-');in=getchar();}
	while(isdigit(in)){ret=ret*10+(in^48);in=getchar();}
	return (opt?-ret:ret);
}
int dotc,proc,knum,ret;
int del[110],dis[110];
vector<int>lins[1000010];
int dfs0(int pos,int pre){
	if(del[pos])return 0;
	int ret=INT_MAX;
	for(int suc:lins[pos]){
		if(suc==pre)continue;
		ret=min(ret,dfs0(suc,pos)+1);
	}return ret;
}void dfs2(int pos){
	if(!del[pos])return ;
	if(dis[pos])return ;dis[pos]=1;
	for(int suc:lins[pos])dfs2(suc);
}void dfs1(int pos,int sum){
	if(pos>dotc){
		if(sum!=knum)return ;
		int tot=0;
		for(int i=1;i<=dotc;i+=1)dis[i]=0;
		for(int i=1;i<=dotc;i+=1){
			if(!dis[i] and del[i])dfs2(i),tot+=1;
			if(tot>2)return ;
		}int now=0;
		for(int i=1;i<=dotc;i+=1){
			now=max(now,dfs0(i,0));
		}ret=min(ret,now);return ;
	}dfs1(pos+1,sum);del[pos]=1;
	dfs1(pos+1,sum+1);del[pos]=0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int test=read();proc=read();
	for(int t=1;t<=proc;t+=1){
		dotc=read();knum=read();ret=INT_MAX;
		for(int i=1;i<=dotc;i+=1)lins[i].clear();
		for(int i=1;i<dotc;i+=1){
			int u=read(),v=read();
			lins[u].push_back(v);
			lins[v].push_back(u);
		}dfs1(1,0);printf("%lld\n",ret);
	}return 0;
}