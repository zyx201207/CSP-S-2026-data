#include<bits/stdc++.h>
using namespace std;
const int M = 500005,N = 505,D = 25;
int c,n,m,d,q;
int w[M],k[N],a[N][D],t[N][D],dp[N][N],x,y;
int cn[M][D],cnt[M];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)cin>>w[i];
	for(int i = 1;i<=n;i++){
		cin>>k[i];
		for(int j = 1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			cnt[a[i][j]]++;
			cn[a[i][j]][cnt[a[i][j]]] = k[i];
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<x+y<<endl;
	}
	return 0;
}
