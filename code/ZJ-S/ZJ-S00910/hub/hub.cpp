#include<bits/stdc++.h>
using namespace std;
int op,T,i,x,y,k,n,m,mi,j,b[4010],g[4010],c[4010],e[4010],t,F[4010][4010];
vector<int>f[4010];pair<int,int>a[4010];
int js(){
	int i,j,ma=0;
	for(i=1;i<=n;i++){
		if(!b[i]){
			int A=2e9;
			for(j=1;j<=n;j++){
				if(b[j]){
					A=min(A,F[i][j]);
				}
			}ma=max(ma,A);
		}
	}return ma;
}int find(int x){
	return x==g[x]?x:g[x]=find(g[x]);
}void pd(){
	int i,j,s=0,x,y,w=0;
	t=0;
	for(i=1;i<=n;i++){
		e[i]=0;
		g[i]=i;
	}for(i=1;i<=n;i++){
		if(b[i]){
			c[++t]=i;
		}
	}for(i=1;i<=t;i++){
		for(j=1;j<i;j++){
			if(F[c[i]][c[j]]==1){
				a[++w]={i,j};
			}
		}
	}for(i=1;i<=w;i++){
		x=find(a[i].first);
		y=find(a[i].second);
		if(x!=y){
			g[x]=y;
		}
	}for(i=1;i<=t;i++){
		find(c[i]);
		if(e[g[c[i]]]){
			;
		}else{
			s++;
			e[g[c[i]]]=1;
		}
	}if(s<=2){
		mi=min(mi,js());
	}
}void dfs(int x,int y){
	if(y==m){
		pd();
		return ;
	}if(x>n){
		return ;
	}b[x]=1;dfs(x+1,y+1);
	b[x]=0;dfs(x+1,y);
}int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>op>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;i++){
			f[i].clear();
		}memset(F,0x3f,sizeof(F));
		for(i=1;i<n;i++){
			cin>>x>>y;
			F[x][y]=F[y][x]=1;
			f[x].push_back(y);
			f[y].push_back(x);
		}for(k=1;k<=n;k++){
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					F[i][j]=min(F[i][j],F[i][k]+F[k][j]);
				}
			}
		}mi=2e9;dfs(1,0);
		cout<<mi<<"\n";
	}return 0;
}
