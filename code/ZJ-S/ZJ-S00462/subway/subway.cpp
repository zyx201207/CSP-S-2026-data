#include<bits/stdc++.h>
using namespace std;
const int N=20006;
int w[N],l,r;
struct node{
	int x,t;
};
int inf;
int vx[501],vd[N],ans,ansx[N][N];
vector<node>a[501],b[N];
void dfs(int x,int op,int time){ 
	if(time>=ans)return;
	if(op==0){
		if(x==r){
			ans=min(ans,time+w[x]);
			ansx[l][r]=ans;
			return;
		}
		vd[x]=1;
		for(auto i:b[x]){
			if(!vx[i.x])dfs(i.x,1,time+i.t);
		}	
	}else if(op==1){
		vx[x]=1;
		for(auto i:a[x]){
			if(!vd[i.x]){
				if(i.x!=r)ansx[l][i.x]=min(time+i.t+w[i.x],ansx[l][i.x]);
				dfs(i.x,0,time+i.t);	
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	memset(ansx,0x3f,sizeof(ansx));
	inf=ansx[0][0];
	for(int i=1;i<=m;i++){
		cin>>w[i];	
	}
	for(int i=1;i<=n;i++){
		int k,t,u;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&t,&u);
			a[i].push_back({t,u});
			b[t].push_back({i,u});
		}
	}
	for(int i=1;i<=q;i++){	
		cin>>l>>r;
		if(ansx[l][r]!=inf){
			printf("%d\n",ansx[l][r]);
			continue;
		}
		ans=INT_MAX;
		memset(vx,0,sizeof(vx));
		memset(vd,0,sizeof(vd));
		dfs(l,0,w[l]);
		printf("%d\n",ans);
	}
	return 0;
}

