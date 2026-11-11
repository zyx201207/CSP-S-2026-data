#include<bits/stdc++.h>
using namespace std;

int n,d,ans;
const int N=5010;
int e[N][N];
int len[N];
int x[N];
int vis[N];

int step[N][N];
int stp[N];

void dfs(int u,int sp){
	//cout<<u<<" "<<sp<<"\n";
	step[u][sp]++;
	stp[u]=min(sp,stp[u]);
	if(sp>stp[u]) return ;
	vis[u]=1;
	for(int i=1;i<=len[u];i++){
		int v=e[u][i];
		if(vis[v]) continue;
		dfs(v,sp+1);
	}
	vis[u]=0;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		memset(e,0,sizeof e);
		memset(len,0,sizeof len);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(x[j]-x[i]<=d&&i!=j){
					e[i][++len[i]]=j;
					e[j][++len[j]]=i;
				}
	/*	for(int i=1;i<=n;i++){
			for(int j=1;j<=len[i];j++){
				cout<<e[i][j]<<" ";
			}
			cout<<"\n";
		}*/
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof vis);
			memset(step,0,sizeof step);
			memset(stp,0x3f,sizeof stp);
			dfs(i,0);
		/*	for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++)
					cout<<step[j][k]<<" ";
				cout<<endl;
			}*/
		//	cout<<endl;
			for(int j=1;j<=n;j++){
				if(i!=j){
					for(int k=1;k<=n;k++){
						if(step[j][k]==2){
							ans++;
						//	cout<<i<<" "<<j<<" "<<k<<" "<<endl;	
						}
						if(step[j][k]) break;
					}
				}
			}
		}
		cout<<ans/2<<"\n";
	}
	return 0;
}