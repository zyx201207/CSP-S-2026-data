#include<bits/stdc++.h>
using namespace std;
const int N=6e3+9;
int n,t,ans,c,k,vis[N],fa[N],dep[N],sz[N],top[N],hson[N];
int pl[N];
int sum[N];
int dis[N];
vector<int>mp[N];
void dfs1(int pos,int dad){
	fa[pos]=dad;
	dep[pos]=dep[dad]+1;
	//qp[pos]=dp;
	sz[pos]=1;
	for(int i=0;i<mp[pos].size();i++){
		int son=mp[pos][i];
		if(son!=dad){
			dfs1(son,pos);
			sz[pos]+=sz[son];
			if(sz[son]>sz[hson[pos]])hson[pos]=son;
		}
	}
	return ;
}
void dfs2(int pos,int tp){
	top[pos]=tp;
	if(hson[pos])dfs2(hson[pos],tp);
	for(int i=0;i<mp[pos].size();i++){
		int son=mp[pos][i];
		if(son!=hson[pos]&&son!=fa[pos]){
			dfs2(son,son);
		}
	}
	return ;
}
bool cmp(int x,int y){
	return sum[x]>sum[y];
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
	//	cout<<x;
		x=fa[top[x]];
	}
	return dep[x]>dep[y]?y:x;
}
//vector<vector<int> >mp;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		//cout<<1;
		dep[0]=-1;
	    scanf("%d %d",&n,&k);
	    for(int i=1;i<=n;i++){hson[i]=0;
	    	mp[i].clear();sum[i]=0;	pl[i]=i;
		}
	    for(int i=1;i<n;i++){
	    	int x,y;
	    	scanf("%d %d",&x,&y);
	    	mp[x].push_back(y);
	    	mp[y].push_back(x);
	    
		}//cout<<2;
	    dfs1(1,0);//cout<<4;
    	dfs2(1,1);//cout<<5;
    	for(int i=1;i<=n;i++){
    		dis[i]=1e9;
    		for(int j=1;j<=n;j++){
    			dis[i]=min(dis[i],dep[i]+dep[j]-lca(i,j));
			}sum[dis[i]]++;
		}
		sort(pl+1,pl+1+n,cmp);
		int pos=0,num=0;
		for(int l=n;l>0;l--){
			while(pos<=n&&sum[pl[pos]]>l){
				pos++;
				num++;
			}
			if(k<num){
				printf("%d\n",l+1);goto end;
			}
		}
		printf("1\n");
		end:;
		//cout<<"\n\n";
	}
	
	return 0;
}