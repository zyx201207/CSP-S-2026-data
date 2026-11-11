#include<bits/stdc++.h>
#define int long long 
#define ll long long 
#define ld long double
#define db double
using namespace std;
const int N=2e6+5;
int c,T,n,d,a[N],dp[N][2],nex[N];
/*

比前两题难多了
思考什么时候会出现两条最短路
感觉这题是神秘找性质题啊
怎么这么困难
目前并不知道给的几个特殊性质有什么用，可以从这个地方下手
感觉目前想的思路和很多步骤分都有关联
继续！
思考本题是否可能是dp
看上去应该就是dp
*/
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		memset(nex,0,sizeof(nex));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}	
		for(int i=1;i<=n;i++){
			nex[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
		}
		dp[1][0]=dp[1][1]=0;
		for(int i=2;i<=n;i++){
			if(nex[i]==i-1){
				dp[i][0]=dp[i-1][0];
				dp[i][1]=dp[i-1][1]+1;
			}else if(nex[i]==i){
				dp[i][0]=dp[i][1]=0;
			}else{
				if(a[nex[i]+1]-a[nex[nex[i]]]>d){
					dp[i][0]=dp[nex[i]][0]+(nex[i]-nex[nex[i]+1]);
					dp[i][1]=dp[nex[i]][1]+i-nex[i]-(nex[i]-nex[nex[i]+1]);
					if(nex[i]==i-2)continue;
					dp[i][0]-=nex[i]-nex[nex[i]+2];
					continue;
				}
				int pd=0;
				if(nex[i]==i-2){
					pd=1;
				}else if(a[nex[i]+2]-a[nex[nex[i]]]>d){
					pd=1;
				}
				if(pd){
					dp[i][0]=dp[nex[i]][1];
					dp[i][1]=i-nex[i];
					if(nex[i]==i-2)continue;
					dp[i][0]-=nex[i]-nex[nex[i]+2];
				}else{
					dp[i][0]=0;
					dp[i][1]=i-nex[i];
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=dp[i][0];
		//	cout<<dp[i][0]<<" "<<dp[i][1]<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 5
6 4
-3 0 1 2 3 4
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
6 3
0 1 2 3 4 7
8 3
0 1 2 4 8 10 11 13
1 3
0
*/