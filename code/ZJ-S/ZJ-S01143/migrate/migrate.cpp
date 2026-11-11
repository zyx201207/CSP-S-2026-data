#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500001],k[500001],a[501][50001],t[501][50001];
int p[500005];
int ft[505][500005];
vector<int>line[500005];//mei ge dian suo zai lu xian
int line_[500005];
int vis[505];
struct node{
	int sum;int l;
};
node dfs(int line1,int x,int sum,int y){
	if(ft[line1][x]&&ft[line1][y])return {sum,line1};
	vis[line1]=1;
	int ans=sum;
	int lll=1e9;
	for(int i=1;i<=k[line1];i++){
		for(int j=1;j<=line[a[line1][i]].size();j++){
			int jiedian=a[line1][i];
			int line2=line[jiedian][j];
			if(!vis[line2]){
				node t=dfs(line2,jiedian,ans+ft[line1][jiedian],y);
				if(ans+ft[line1][jiedian]+ft[line2][jiedian]+t.sum>sum){
					sum=ans+ft[line1][jiedian]+ft[line2][jiedian]+t.sum;
					lll=t.l;
				}
				sum=max(sum,ans+ft[line1][jiedian]+ft[line2][jiedian]+t.sum);
			}
		}
	}
	vis[line1]=0;
	node r;
	r.sum=sum;
	if(lll==1e9)r.l=line1;
	else r.l=lll;
	return r;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			ft[i][a[i][j]]=t[i][j];
			line[a[i][j]].push_back(i);
			line_[a[i][j]]++;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(n==1)cout<<w[x]+w[y];
		else if(n==2){
			if(ft[1][x]&&ft[1][y]){
				cout<<w[x]+w[y]+ft[1][x]+ft[1][y];
			}else if(ft[2][x]&&ft[2][y])cout<<w[x]+w[y]+ft[2][x]+ft[2][y];
			else{
				int x1=0;
				for(int i=1;i<=k[1];i++)
				    if(line_[a[1][i]]==2){
					    x1=a[1][i];
					    break;
				    }
				int aans=w[x]+w[y]+ft[1][x1]+ft[2][x1];
				if(ft[1][x])cout<<aans+ft[1][x]+ft[2][y];
				else cout<<aans+ft[1][y]+ft[2][x];
			}
		}else{
			int ans1=0;
			for(int i=1;i<=n;i++)if(ft[i][x]){
				node op=dfs(i,x,0,y);
				ans1=min(ans1,op.sum+ft[i][x]+ft[op.l][y]);
			}
			cout<<ans1+w[x]+w[y];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}