#include<bits/stdc++.h>
using namespace std;
int i,n,k,T,x,y,t,w,c,j,mid,bao,fl[1000010],fa[1000010],e[4010][30],a[1000010];
vector<int>f[1000010];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void dfsx(int x,int fx){
	int i,sx;
	for(i=0;i<f[x].size();i++){
		sx=f[x][i];
		if(sx==fx)continue;
		e[sx][0]=x;dfsx(sx,x);
	}
}
bool xx(int x,int fx,int c){
	int i,sx;bool lf=0;
	if(c==0)return fl[x];
	for(i=0;i<f[x].size();i++){
		sx=f[x][i];
		if(sx==fx)continue;
		lf=lf||xx(sx,x,c-1);
	}
	return lf||fl[x];
}
void dfs(int x,int fx){
	int i,sx,y,yy;
	for(i=0;i<f[x].size();i++){
		sx=f[x][i];
		if(sx==fx)continue;
		dfs(sx,x);
	}
	
	yy=x;
	if(fl[yy]==0&&xx(x,e[x][0],mid)==0){
		for(i=1;i<=mid;i++){
			if(e[yy][0]!=0)yy=e[yy][0];
			if(fl[yy]==1)break;
		}
		if(fl[yy]==0)fl[yy]=1;
	}
}
bool check(){
	int ans=0,w=0,j,i;
	memset(fl,0,sizeof(fl));
	dfs(1,0);
	for(i=1;i<=n;i++){
		ans+=fl[i];w++;a[w]=i;
	}
	for(i=1;i<=w;i++)fa[i]=i;
	if(ans>k)return 0;
	if(ans<=2)return 1;
	for(i=1;i<=w;i++)
		for(j=1;j<=w;j++)
			if(find(i)!=find(j)&&(a[i]==e[a[j]][0]||a[j]==e[a[i]][0]))
				fa[find(j)]=find(i);
	ans=0;
	for(i=1;i<=w;i++)
		if(find(i)==i)ans++;
	return ans<=2;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(i=1;i<n;i++)
			cin>>x>>y,f[x].push_back(y),f[y].push_back(x);
		dfsx(1,0);
		for(i=1;i<=20;i++)
			for(j=1;j<=n-(1<<i)+1;j++)
				e[j][i]=e[j-1][e[j-1][i]];
//		mid=1;
//		check();
		t=0;w=n-k;
		while(t<=w){
			mid=(t+w)/2;
			if(check())bao=mid,w=mid-1;
			else t=mid+1;
		}
		cout<<bao<<"\n";
		for(i=1;i<=n;i++)f[i].clear();
	}
	return 0;
}
