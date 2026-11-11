#include<bits/stdc++.h>
#define int long long
#define fileio
//#define opensync
//#define multicase
using namespace std;
int c,t,n,d,x[2000005],g[5005][5005],cnt[5005][5005],ans; 
void INIT(){

}
void MAIN(int CASE){
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				g[i][j]=INT_MAX/2*(i!=j);
				cnt[i][j]=0;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				if(x[i]-x[j]<=d){
					cnt[i][j]=cnt[j][i]=g[i][j]=g[j][i]=1;
				}
			}
		}
		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(g[i][j]==g[i][k]+g[k][j]){
						cnt[i][j]+=cnt[i][k]*cnt[k][j];
					}
					if(g[i][j]>g[i][k]+g[k][j]){
						g[i][j]=g[i][k]+g[k][j];
						cnt[i][j]=cnt[i][k]*cnt[k][j];
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				ans+=cnt[i][j]==2;
			}
		}
		cout<<ans/2<<'\n';
	}
}
signed main(){
#ifndef opensync
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
#ifdef fileio
	ifstream fin("migrate.in");
	ofstream fout("migrate.out");
	auto oldcin=cin.rdbuf(fin.rdbuf());
	auto oldcout=cout.rdbuf(fout.rdbuf());
#endif
	int t=1;
#ifdef multicase
	cin>>t;
#endif
	INIT();
	for(int i=0;i<t;i++){
		MAIN(i);
	}
#ifdef fileio
	cin.rdbuf(oldcin);
	cout.rdbuf(oldcout);
#endif
	return 0;
}
/*
16:03
不难发现对所有距离<=d的点连边，然后最短路计数可以做到O(n^3)
双指针扫一遍？
像SCPST2的那样 
问题就变成了如何判定u->v的路径有两条
这样如果每次暴力做一遍dp判定的话是O(n^2)的
可以拿到40pts。 

特殊性质A是好做的

16:16
先看D的暴力 

17:23
I'm back.
我会48pts
写！ 

17:35
不对这是n^3的，不会n^2。坏了这咋办
不管了，开写 

17:58
不对读错题了！！！
还是跑APSP吧 

18:04
哇，题面出锅，还有保留节目（ 

18:16
过了大样例。 
*/ 
