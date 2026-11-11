#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int c,n,m,d,q;
bool way[2001][2001];//线路所经站台 
int w[2001];//进站时间 
int t[2001][2001];//站台、线路 (m,n)时间 
int s,e;//起点和终点 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,l;
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>l;
			way[i][l]=1;
			cin>>t[l][i];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s>>e;
		int sum=0;
		sum+=(w[s]+w[e]);
		cout<<sum+10<<endl;
	}
	return 0;
} 
