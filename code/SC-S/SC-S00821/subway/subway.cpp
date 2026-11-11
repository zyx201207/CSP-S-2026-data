#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,k,x,y,ans,sum;
int w[500005];
struct node{
	int a;
	int t;
};
vector<node> a[500005],b[505];
int mp[505][505],mi[505][505],bp[505];
int solve(int p,int q){
	if(mi[p][q]!=-1) return mi[p][q];
	else{
		mi[p][q]=1e18;
		for(int i=0;i<b[p].size();i++){
			if(bp[b[p][i].a]==0){
				bp[b[p][i].a]=1;
				mi[p][q]=min(solve(b[p][i].a,q)+b[p][i].t,mi[p][q]);
				bp[b[p][i].a]=0;
			}
		}
		mi[q][p]=mi[p][q];
		return mi[p][q];
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>c>>n>>m>>d>>q;
	memset(mi,-1,sizeof(mi));
	for(int i=1;i<=n;i++){
		mi[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			a[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			for(int k=j+1;k<a[i].size();k++){
				if(mp[a[i][j].a][a[i][k].a]==0){
					mp[a[i][j].a][a[i][k].a]=a[i][j].t+a[i][k].t;
				}
				else{
					mp[a[i][j].a][a[i][k].a]=min(a[i][j].t+a[i][k].t,mp[a[i][j].a][a[i][k].a]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]!=0){
				b[i].push_back({j,mp[i][j]});
				b[j].push_back({i,mp[i][j]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mi[i][j]=solve(i,j);
			memset(bp,0,sizeof(bp));
		}
	}
	while(q--){
		ans=0,sum=1e18;
		cin>>x>>y;
		ans+=(w[x]+w[y]);
		for(int i=0;i<a[x].size();i++){
			for(int j=0;j<a[y].size();j++){
				memset(bp,0,sizeof(bp));
				sum=min(sum,a[x][i].t+a[y][j].t+solve(a[x][i].a,a[y][j].a));
			}
		}
		ans+=sum;
		cout<<ans<<endl;
	}
	return 0;
}
