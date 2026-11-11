#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=505,maxm=1e4+5000;
int c,d,n,m,q;
ll dis[maxm][maxm];
int w[maxm];
int a[maxn][21];
ll t[maxn][21];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k;j++){
			for(int h=j+1;h<=k;h++){
				dis[a[i][j]][a[i][h]]=min(dis[a[i][j]][a[i][h]],t[i][j]+t[i][h]);
				dis[a[i][h]][a[i][j]]=dis[a[i][j]][a[i][h]];
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		cout<<w[s]+dis[s][t]+w[t]<<endl;
	}
	return 0;
}

