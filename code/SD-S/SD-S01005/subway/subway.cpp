#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,dd,qq,vis[2500009],f[2500009],nex[4100009],firs[4100009],to[4100009],e[4100009],cnt,res,ans[200009];
struct node{
	int l,r,ii;
}w[100009];
void add(int x,int y,int z){
	cnt++;
	e[cnt]=z;
	to[cnt]=y;
	nex[cnt]=firs[x];
	firs[x]=cnt;
}
struct rode{
	int x,y;
	bool operator<(const rode &a)const{
		return y>a.y;
	}
};
void djstl(int s){
	for(int i=1;i<=res+5;i++) f[i]=1e18,vis[i]=0;
	f[s]=0;
	priority_queue<rode> q;
	q.push((rode){s,0});
	while(!q.empty()){
		int u=q.top().x;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=firs[u];i;i=nex[i]){
			int y=to[i];
			if(f[y]>f[u]+e[i]){
				f[y]=f[u]+e[i];
				q.push((rode){y,f[y]});
			}
		}
	}
}
bool cmp(node x,node y){
	return x.l<y.l;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>dd>>qq;
	res=n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		add(i,++res,x);
		add(res,i,x);
	}
	for(int i=1;i<=m;i++){
		int k,kk=0;
		cin>>k;
		while(k--){
			int cc,t;
			cin>>cc>>t;
			add(cc+n,++res,t);
			add(res,cc+n,t);
			if(kk) add(kk,res,0),add(res,kk,0);
			kk=res;
		}
	}
	for(int i=1;i<=qq;i++) cin>>w[i].l>>w[i].r,w[i].ii=i;
	sort(w+1,w+qq+1,cmp);
	for(int i=1,j=1;i<=n;i++){
		djstl(i);
		while(w[j].l==i) ans[w[j].ii]=f[w[j].r],j++;
	}
	for(int i=1;i<=qq;i++) cout<<ans[i]<<'\n';
	
	
	
	
	return 0;
}
/*
³æÐè
ÔÆÁ¦
°×É×
³æÇÒ 
*/
