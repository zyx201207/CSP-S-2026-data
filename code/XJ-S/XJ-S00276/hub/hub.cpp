#include<bits/stdc++.h>
using namespace std;
const int  N=1e4+900;
int jld[N],bj[N][N],zuida[N],zuidadian[N],lmg[N];
vector<int>t[N];
int dfs(int u,int fa){
	//cout<<t[u].size();
	int mn=0;
	for(int i=0;i<lmg[u];i++){
		//	cout<<u<<endl;;
		if(t[u][i]==fa){
			continue;
		}
		
		if(jld[t[u][i]]==1){
			return t[u][i];
		}
		int bl=dfs(t[u][i],u);
		//cout<<bl;
		if(bj[mn][u]>bj[bl][u]){
			mn=bl; 
		}
	}
	return mn;
}
void zbdfs(int u,int fa,int dep,int now){
	bj[now][u]=dep;
//	int mn=1e9;
	for(int i=0;i<lmg[u];i++){
		if(t[u][i]==fa){
			continue;
		}
		
		zbdfs(t[u][i],u,dep+1,now);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int my,T;
	cin>>my>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			t[u].push_back(v);
			t[v].push_back(u); 
		}
		int ls=0;
	//	cout<<endl<<t[5].size()<<endl;;
		for(int i=1;i<=n;i++){
		//	cout<<t[i].size();
			lmg[i]=t[i].size();
			if(lmg[i]==2){
				jld[i]=1;	
				zbdfs(i,0,0,i);
			}
		}
		
		for(int i=1;i<=n;i++){
		//	cout<<1;
			if(jld[i]==0){
				int ds;
				ds=dfs(i,0);
				zuida[i]=bj[ds][i];
				zuidadian[i]=ds;
			}
		}
	//	cout<<1;
		int mx=-1;
		sort(zuida+1,zuida+n+1);
		int k2=k;
		for(int i=1;i<=k;i++){
			if(zuida[i]==0){
				k++;
				continue; 
			}
			//cout<<zuida[i]<<" "<<i<<" "<<endl;;
			 mx=max(mx,zuida[i]);
		} 
		cout<<mx<<endl;
		memset(zuida,0,sizeof(zuida));
		memset(zuidadian,0,sizeof(zuidadian));
		memset(bj,0,sizeof(bj));
		memset(t,0,sizeof(t));
		memset(jld,0,sizeof(jld));
		memset(lmg,0,sizeof(lmg));
}


	return 0;
} 
