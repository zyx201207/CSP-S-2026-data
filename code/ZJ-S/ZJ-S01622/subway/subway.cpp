#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const int N=505,M=500005;
int c,n,m,d,q;
int w[M];
int k,a,t[N][M];//k[i][j]表示第i条线站台 到 j站厅 时间 
int x,y;
ll sum,o;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){//线 
		cin>>k;//站台数 
		for(int j=1;j<=k;j++){
			cin>>a>>t[i][a];
		}
	} 
	cin>>q;
	while(q--){
		sum=0;
		cin>>x>>y;
		sum+=w[x]+w[y];
		cout<<sum<<endl;
	} 
	return 0;
} 
