#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> P;
const int maxn=505;
const int maxm=5e5+5;
int n,m,d,q,dis[maxn][maxn],qwq[maxm];
struct node{
	int x,t;
	bool operator<(const node &oth)const{
		return x<oth.x;
	}
};
vector<node> ln[maxm];
vector<P> tt[maxm];
int calc(int x,int y){
	int ans=4e18;
	for(int i=0,j=0;i<ln[x].size();i++){
		auto[p,t1]=ln[x][i];
		while(j<ln[y].size()&&ln[y][j].x<p) j++;
		if(j<ln[y].size()&&ln[y][j].x==p) ans=min(ans,t1+ln[y][j].t);
	}
	return ans;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>qwq[i];
	for(int i=1;i<=n;i++){
		int tmp;cin>>tmp;
		while(tmp--){
			int x,t;cin>>x>>t;
			ln[i].push_back((node){x,t});
			tt[x].push_back(P{i,t});
		}
		sort(ln[i].begin(),ln[i].end());
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		for(int j=i+1;j<=n;j++)
	dis[i][j]=dis[j][i]=calc(i,j);
	}
	
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;cin>>x>>y;int ans=4e18;
		for(auto&[i,t1]:tt[x])
		for(auto&[j,t2]:tt[y]) {
			ans=min(ans,qwq[x]+qwq[y]+t1+t2+dis[i][j]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}