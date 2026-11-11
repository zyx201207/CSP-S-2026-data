#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[505],k[505],a[505][505],t[505][505],vis[505],zhan[505][505],cntzhan[505],fr,too,ans;
void dfs(int sta, int linne, int tim){
	if(sta==too){
		ans=min(tim+t[linne][sta],ans);
	}
	if(tim>=ans){
		return;
	}
	for(int i=1;i<=cntzhan[sta];i++){
		if(zhan[sta][i]==linne){
			for(int j=1;j<=k[linne];j++){
				if(a[linne][j]==sta){
					continue;
				}
				else if(!vis[a[linne][j]]){
					vis[a[linne][j]]=true;
					dfs(a[linne][j],linne,tim);
					vis[a[linne][j]]=false;
				}
			}
		}
		else{
			int newlinne=zhan[sta][i];
			int lin=tim+t[linne][sta]+t[newlinne][sta];
			for(int j=1;j<=k[newlinne];j++){
				if(a[newlinne][j]==sta){
					continue;
				}
				else if(!vis[a[newlinne][j]]){
					vis[a[newlinne][j]]=true;
					dfs(a[newlinne][j],newlinne,lin);
					vis[a[newlinne][j]]=false;
				}
			}
		}
		
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
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][a[i][j]];
			cntzhan[a[i][j]]++;
			zhan[a[i][j]][cntzhan[a[i][j]]]=i;
		}
	}
	for(int i=1;i<=q;i++){
		for(int j=0;j<505;j++){
			vis[j]=false;
		}
		ans=2147483647;
		cin>>fr>>too;
		for(int j=1;j<=cntzhan[fr];j++){
			dfs(fr,zhan[fr][j],t[zhan[fr][j]][fr]);
		}
		if(i<q)
			cout<<ans+w[fr]+w[too]<<endl;
		else{
			cout<<ans+w[fr]+w[too];
		}
	}
	return 0;
}