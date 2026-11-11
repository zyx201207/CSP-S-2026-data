#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500010];
struct node{int to,df;};
vector<node> rr[500010];
int e[510][510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int af,t;cin>>af>>t;
			node f;f.to=i,f.df=t;
			rr[af].push_back(f);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)e[i][j]=1e18;
	for(int i=1;i<=m;i++){
		int tt=rr[i].size();
		for(int j=0;j<tt;j++)
			for(int k=j+1;k<tt;k++){
				int to1=rr[i][j].to,to2=rr[i][k].to;
				int dt=rr[i][j].df+rr[i][k].df;
				e[to1][to2]=e[to2][to1]=min(e[to1][to2],dt);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(e[i][j]>e[i][k]+e[k][j])
					e[i][j]=e[i][k]+e[k][j];
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			cout<<e[i][j]<<' ';
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		int sr,tr;cin>>sr>>tr;
		int sl=rr[sr].size();
		int tl=rr[tr].size();
		int ans=1e18;
		for(int j=0;j<sl;j++)
			for(int k=0;k<tl;k++){
				//cout<<i<<' '<<j<<' '<<k<<endl;
				int st=rr[sr][j].to,tt=rr[tr][k].to;
				int sd=rr[sr][j].df,td=rr[tr][k].df;
				ans=min(ans,w[sr]+w[tr]+sd+td+e[st][tt]);
			}
		cout<<ans<<'\n';
	}
	return 0;
}
