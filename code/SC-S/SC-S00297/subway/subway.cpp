#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3+5,MAXM=5e5+5;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
long long c[MAXN][MAXN];
int ghj,n,m,d,q;
	long long w[MAXM];
	cin>>ghj>>n>>m>>d>>q;
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m;j++) c[i][j]=1000000000000000;
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int g;
		cin>>g;
		for(int j=1;j<=g;j++){
			int a,b;
			cin>>a>>b;
			c[a][m+i]=c[m+i][a]=b;
		}
	}
	for(int i=1;i<=m+n;i++){
		for(int j=i+1;j<=m+n;j++){
			for(int k=1;i<=n;i++){
				if(k==i||k==j) continue;
				c[j][i]=c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
			}
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<c[a][b]+w[a]+w[b]<<endl;
	}
	return 0;
} //I wanna AK CSP-J/S,but I can't.