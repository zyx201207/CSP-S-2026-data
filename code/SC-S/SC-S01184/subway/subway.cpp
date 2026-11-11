#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int c,n,m,d,q;
int w[N],a[510][N],t[510][N];
int ans[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(ans,0x3f,sizeof ans);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<x;j++){
			for(int v=j+1;v<=x;v++){
				ans[a[i][j]][a[i][v]]=t[i][j]+t[i][v];
				ans[a[i][v]][a[i][j]]=t[i][j]+t[i][v];
			}
		}
	}
	for(int i=1;i<=m;i++){
		ans[i][i]=0;
	}
	for(int i=1;i<m;i++){
		for(int j=i+1;j<=m;j++){
			for(int v=1;v<=m && v!=i && v!=j;v++){
				ans[i][j]=min(ans[i][j],ans[i][v]+ans[j][v]);
				ans[j][i]=ans[i][j];
			}
		}
	}
	while(q--){
		int head,tail;
		cin>>head>>tail;
		cout<<ans[head][tail]+w[head]+w[tail]<<"\n";
	}
	return 0;
}