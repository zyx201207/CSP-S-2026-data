#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,s,e;
long long minn=1e18;
vector<int> g[N],onway[N];
int a[N],t[505][N],vis[N],w[N];
bool isor(int sta,int ww){
	for(int i=0;i<onway[sta].size();i++){
		if(onway[sta][i]==ww){
			return true;
		}
	}
	return false;
}
void dfs(int x,long long sum,int ow){
	vis[x]=1;
	if(x==e&&isor(x,ow)){
		//cout<<w[e]+t[ow][e]<<"jieguo "<<sum<<" "<<ow<<endl;
		minn=min(minn,sum+w[e]+t[ow][e]);
		//cout<<minn<<" jie"<<endl;
		return;
	}
	for(int i=0;i<g[x].size();i++){
		if(vis[g[x][i]]==1)continue;
		vis[g[x][i]]=1;
		for(int j=0;j<onway[g[x][i]].size();j++){
			if(onway[g[x][i]][j]==0)continue;
			if(onway[g[x][i]].size()<=1){
				//cout<<g[x][i]<<" "<<sum<<" "<<ow<<"(<1)"<<endl;
				dfs(g[x][i],sum,ow);
			}else if(ow==onway[g[x][i]][j]){
				dfs(g[x][i],sum,ow);
			}else{
				//cout<<g[x][i]<<" "<<t[ow][g[x][i]]<<" "<<t[onway[g[x][i]][j]][g[x][i]]<<" "<<ow<<" "<<onway[g[x][i]][j]<<"guocheng"<<endl;
				dfs(g[x][i],sum+t[ow][g[x][i]]+t[onway[g[x][i]][j]][g[x][i]],onway[g[x][i]][j]);
			}
			vis[g[x][i]]=0;
		}
		vis[g[x][i]]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j];
			cin>>t[i][a[j]];
			onway[a[j]].push_back(i);
			if(j>1){
				g[a[j]].push_back(a[j-1]);
				g[a[j-1]].push_back(a[j]);
			}
		}
		/*for(int j=1;j<=k;j++){
			cout<<a[j]<<"tou ";
			for(int o=0;o<onway[a[j]].size();o++){
				cout<<onway[a[j]][o]<<" ";
			}
			cout<<"lian"<<endl;
		}*/
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;*/
	for(int i=1;i<=q;i++){
		cin>>s>>e;
		for(int j=0;j<onway[s].size();j++){
			if(onway[s][j]==0)continue;
			dfs(s,w[s]+t[onway[s][j]][s],onway[s][j]);
		}
		if(minn==1e18){
			cout<<0<<endl;
		}else{
			cout<<minn<<endl;
		}
		minn=1e18;
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
