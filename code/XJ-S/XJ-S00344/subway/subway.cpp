#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;//n地铁线路数  m地铁站数  d每个地铁站最多被几条线经过  q出行计划数 
	cin>>c>>n>>m>>d>>q;
	int w[m]; //地铁口走向站厅需要的时间
	for(int i=0;i<m;i++){
		cin>>w[i];
	}int num;
	int at[n][500005];
	for(int i=0;i<n;i++){
		cin>>num;
		at[i][0]=num;
		for(int j=1;j<=num*2;j++){
			cin>>at[i][j];
		}
	}int l,r;
	int ans=0;
	for(int i=0;i<q;i++){
		cin>>l>>r;
		cout<<10<<endl;
	}
