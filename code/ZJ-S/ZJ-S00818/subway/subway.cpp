#include<bits/stdc++.h>
using namespace std;
const int N=125505;
const int M=5e2+5;
long long n,m,q,w[N],a[M][N],t[M][M],o[M][N],x,y,dp[N],k[M];
struct node{
	long long wz,sj;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];cin>>t[i][a[i][j]];
			o[i][a[i][j]]=1;
		}
	}
	while(q--){
		cin>>x>>y;
		queue<node> p;
		p.push({x,0});
		for(int i=1;i<=m;i++){
			dp[i]=INT_MAX;
		}dp[x]=0;
		while(!p.empty()){
			node tt=p.front();
			p.pop();
			for(int i=1;i<=n;i++){
				if(o[i][tt.wz]==1){
					for(int j=1;j<=k[i];j++){
						if(dp[a[i][j]]>tt.sj+t[i][tt.wz]+t[i][a[i][j]]){
							dp[a[i][j]]=tt.sj+t[i][tt.wz]+t[i][a[i][j]];
							p.push({a[i][j],dp[a[i][j]]});
						}
					}
				}
			}
		}
		cout<<dp[y]+w[x]+w[y]<<endl;
	}
	return 0;
}
