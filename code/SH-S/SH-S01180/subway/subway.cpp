#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 100010;
long long c,n,m,d,q;
long long zt[MAXN];
long long station[MAXN][MAXN];
long long dp[MAXN][MAXN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>zt[i];
	}
	for(int i=0;i<n;i++){
		long long k;
		cin>>k;
		for(int j=0;j<k;j++){
			int na;
			cin>>na;
			cin>>station[i][na];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			dp[i][j]=1e18;
		}
	}
	for(int i=0;i<m;i++){
		dp[i][i]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(station[i][j]!=0){
				for(int k=0;k<m;k++){
					if(station[i][k]!=0){
						dp[j][k]=0;
					}
				}
			}
		}
	}for(int i=0;i<q;i++){
		long long x,y;
		cin>>x>>y;
		
	}
}
