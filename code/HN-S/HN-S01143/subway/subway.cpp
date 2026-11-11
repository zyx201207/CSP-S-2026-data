#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10,M=1e3+10;
int tn[N];
vector<int>vn[N];
int an[N],bn[N];
int dp[M][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>tn[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int a,t;
			cin>>a>>t;
			vn[a].push_back(i);
			an[a]=t;
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=min(dp[i][j]+an[i]+an[j]+tn[i]+tn[j],dp[i][k]+dp[k][j]+an[i]+an[j]+an[k]+tn[i]+tn[j]+tn[k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,st=0;
		cin>>x>>y;
		for(int i=1;i<vn[x].size();i++)bn[vn[x][i]]=1;
		for(int i=1;i<vn[y].size();i++){
			if(bn[vn[y][i]]==1){
				st=1;
				break;
			}
		}
		if(st==1){
			cout<<an[x]+an[y]+tn[x]+tn[y];
		}else{
			cout<<dp[x][y];
		}
		cout<<"\n";
	}
	return 0;
}


