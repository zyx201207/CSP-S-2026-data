#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,len,wz,len1;
bool used[1000010];
vector<int>g[1000010];
int read(){
	char ch=getchar();int num=0;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		num=num*10+(ch-'0');
		ch=getchar();
	}
	return num;
}
void dfs(int x,int fa,int step){
	if(step>len){
		len=step;
		wz=x;
	}
	for(int i=0;i<g[x].size();i++){
		if(g[x][i]==fa)continue;
		dfs(g[x][i],x,step+1);
	}
}
void dfs1(int x,int fa,int step){
	used[x]=1;
	len1=max(len1,step);
	for(int i=0;i<g[x].size();i++){
		if(g[x][i]==fa)continue;
		dfs1(g[x][i],x,step+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();k=read();len=len1=wz=0;
		for(int i=0;i<1000010;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0,0);
		dfs1(wz,0,1);
		len1-=k;
		len1=max(len1,0);
		len1=ceil(len1*1.0/3);
		cout<<len1<<endl;
	}
	return 0;
}