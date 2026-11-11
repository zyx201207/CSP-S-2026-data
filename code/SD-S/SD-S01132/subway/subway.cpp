#include<bits/stdc++.h>
using namespace std;
struct node{
	int g,k;
};
int c,n,m,d,q,w[500010],ans,x,y,vis[500010];
vector<node> mp[500010];
void dfs(int p,int val){
	if(p==y){
		ans=min(ans,val);
		return;
	}
	if(vis[p]) return;
	vis[p]=1;
	for(int i=0;i<mp[p].size();i++){
		//cout<<mp[p][i].g<<" "<<mp[p][i].k<<endl;
		dfs(mp[p][i].g,val+mp[p][i].k);
		//vis[mp[p][i].g]=0;
	}
	vis[p]=0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		node lis[p+10];
		for(int j=1;j<=p;j++){
			int a,av;
			cin>>a>>av;
			//cout<<a<<av;
			for(int l=1;l<j;l++){
				node mpp1,mpp2;
				mpp1.g=a;
				mpp1.k=av+lis[l].k;
				mpp2.g=lis[l].g;
				mpp2.k=av+lis[l].k;
				mp[lis[l].g].push_back(mpp1);
				mp[a].push_back(mpp2);
			}
			lis[j].g=a;
			lis[j].k=av;
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<mp[i].size();j++){
//			cout<<mp[i][j].g<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		//cout<<x<<y;
		for(int i=1;i<=m;i++) vis[i]=0;
		ans=2100000000;
		dfs(x,0);
		ans+=w[x];
		ans+=w[y];
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

