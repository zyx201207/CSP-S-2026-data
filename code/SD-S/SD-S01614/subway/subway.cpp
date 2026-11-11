#include<bits/stdc++.h>
using namespace std;
long long n,c,m,d,q,w[10000];
long long ak[10000],dp[600][600],qi,zhi;
struct myst {
	long long dian,dist;
} a[510][3111];
struct ppp {
	long long ddd,nex;
	bool operator <(const ppp& x) const {
		return ddd>x.ddd;
	}
};
priority_queue<ppp> qq,q1;
bool flagg[600][600];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>ak[i];
		for(int j=1; j<=ak[i]; j++) {
			cin>>a[i][j].dian>>a[i][j].dist;
		}
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=m; j++) {
			dp[i][j]=1e11;
			flagg[i][j]=0;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=ak[i]; j++) {
			for(int jj=j+1; jj<=ak[i]; jj++) {
				long long xi=min(a[i][j].dian,a[i][jj].dian);
				long long da=max(a[i][j].dian,a[i][jj].dian);
				dp[xi][da]=min(dp[xi][da],a[i][j].dist+a[i][jj].dist);
			}
		}
	}
	for(int i=1; i<=m; i++) {
		qq=q1;
		for(int j=i+1; j<=m; j++) {
			qq.push({dp[i][j],j});
		}
		ppp xx;
		long long biaoo=i;
		while(!qq.empty()) {
			xx=qq.top();
			qq.pop();
			
			if(flagg[i][xx.nex]==0) {
				biaoo++;
				
				flagg[i][xx.nex]=1;
				dp[i][xx.nex]=xx.ddd;
				if(biaoo==m) break;
				for(int j=i+1; j<=m; j++) {
					if(flagg[i][j]==0) {
						qq.push({dp[xx.nex][j]+xx.ddd,j});
					}
				}
			}
		}
	}
	for(int i=1; i<=q; i++) {
		cin>>qi>>zhi;
		long long aa=min(qi,zhi);
		long long bb=max(qi,zhi);
		cout<<dp[aa][bb]+w[aa]+w[bb]<<endl;
	}
	return 0;
}
//Oct31==Dec25?
/*
0 3 7 20 2 
8 3 6 1 7 2 9 
3 1 4 2 5 5 100 
3 2 6 3 1 7 2 
4 3 2 5 100 4 6 6 7 
1 6 
2 3 

*/
