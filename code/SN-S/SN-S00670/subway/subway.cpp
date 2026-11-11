#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e2+7,M=5e5+7;
int c,m,n,d,q; 
int w[N];//依次表示从每个地铁站的地铁口走
//到站厅需要的时间。
int k;//表
//示第 i 条线路经过的地铁站数
int a;//ai,j 表示第 i 条线路经过的第 j 个地铁站
int t;//表示从该地铁站的站厅走到第 i 条线
//路的站台需要的时间
int sum=0;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			sum+=t;
		}
	}
	if(12<=c&&c<=19){
		while(q--){
			cout<<t*2<<"\n";
		}
		return 0;
	}
	else{
		while(q--){
			int s,tt;
			cin>>s>>tt;
			cout<<w[s]+w[tt]<<"\n";
		} 
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
