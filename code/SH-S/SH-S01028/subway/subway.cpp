#include<bits/stdc++.h>
#define MAX 99824435300000000 
#define int long long
using namespace std;
int c,n,m,d,q;
struct tnode{
	int id,val;
};
tnode st[500002][22];
int stnum[500002];
int vis[502][502];
int w[500005];
void build_map(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=stnum[i];j++){
			for(int k=1;k<=stnum[i];k++){
				vis[st[i][j].id][st[i][k].id]=min(vis[st[i][j].id][st[i][k].id],st[i][k].val+st[i][j].val);
			}
		}
	}
	return;
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				vis[i][j]=min(vis[i][j],vis[i][k]+vis[k][j]);
			}
		}
	}
	return;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) vis[i][j]=0;
			else vis[i][j]=MAX;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			st[a][++stnum[a]].val=t;
			st[a][stnum[a]].id=i;
			//stij:第i站的j号列车到站台的时间 
		}
	}
	build_map();
	floyd();
	for(int i=1;i<=q;i++){
		int ta,tb;
		cin>>ta>>tb;
		int ans=MAX;
		for(int j=1;j<=stnum[ta];j++){
			for(int k=1;k<=stnum[tb];k++){
				ans=min(ans,w[ta]+vis[st[ta][j].id][st[tb][k].id]+w[tb]+st[ta][j].val+st[tb][k].val);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
