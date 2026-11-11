#include<bits/stdc++.h>

using namespace std;
int n;int hsh[20];int jg[20];int dis[20][20];int k;int ans=pow(10,9);
int fa[20];
int find(int p){
	if(p==fa[p]){
		return fa[p];
	}else{
		fa[p]=find(fa[p]);
		return fa[p];
	}
}
void print(){
	int tmp=0;int num[20]={0};
	memset(fa,0,sizeof(fa)); 
	for(int i=1;i<=k;i++){
		fa[jg[i]]=jg[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			if(dis[jg[i]][jg[j]]==1){
				int fa1=find(jg[i]);
				int fa2=find(jg[j]);
				fa[fa1]=fa2;
			} 
		}
	}
	for(int i=1;i<=k;i++){
		int x=find(jg[i]);
		num[x]++;
		if(num[x]==1){
			num[0]++;
		}
	}
	if(num[0]>2){
		return;
	}else{
		int tmp=0;
		for(int i=1;i<=n;i++){
			int y=100;
			for(int j=1;j<=k;j++){
				y=min(y,dis[i][jg[j]]);
			}
			tmp=max(y,tmp);
		}
		ans=min(ans,tmp);
	}
}
void dfs(int k,int maxv){
	for(int i=1;i<=n;i++){
		if(hsh[i]==0){
			hsh[i]=1;
			jg[k]=i;
			if(k==maxv){
				print();
			}else{
				dfs(k+1,maxv);
			}
			hsh[i]=0;
			jg[k]=0;
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	int c;int t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;memset(dis,0x3f,sizeof(dis));memset(hsh,0,sizeof(hsh));memset(jg,0,sizeof(jg));
		for(int i=1;i<=n-1;i++){
			int a;int b;cin>>a>>b;dis[a][b]=1;dis[b][a]=1;
		}
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
		}
		for(int x=1;x<=n;x++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[j][i]=dis[i][j]=min(dis[i][x]+dis[x][j],dis[i][j]);
				}
			}
		}	
		ans=pow(10,9);
		dfs(1,k);
		cout<<ans<<endl;
	}
	return 0;
}