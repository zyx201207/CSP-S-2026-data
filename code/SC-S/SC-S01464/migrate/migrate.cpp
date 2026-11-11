#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int c,t,n,d,a[2000010],dp[5010][5010],dp2[5010][5010]; // dp[i][j] 表示从 i 到 j 的最短路径长度路径 dp2 数量
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>t;
//	cout<<LLONG_MAX<<'\n';
	while(t--){
		cin>>n>>d;
//		cout<<n<<' '<<d<<' ';
		for(int i=1;i<=n;i++) cin>>a[i];
//		cout<<a[2]-a[1]<<'\n';
		a[n+1]=INF;
		a[0]=-INF;
		if(c<=6){
			for(int i=1;i<=n;i++){ // 初始化
				for(int j=1;j<=n;j++){
					dp[i][j]=INF;
					dp2[i][j]=0;
				}
			}
			for(int i=1;i<=n;i++){ // 初始化
				for(int j=i+1;a[j]-a[i]<=d;j++){
					dp[i][j]=dp2[i][j]=1;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					for(int k=j;a[k]-a[j]<=d;k++){
						if(dp[i][k]>dp[i][j]+1){
							dp[i][k]=dp[i][j]+1;
							dp2[i][k]=0;
						}
						if(dp[i][k]==dp[i][j]+1){
							dp2[i][k]+=dp2[i][j];
						}
					}
				}
			}
			int cnt=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dp2[i][j]==2) cnt++;
//					cout<<dp[i][j]<<' '<<dp2[i][j]<<' ';
				}
//				cout<<'\n';
			}
			cout<<cnt<<'\n';
		}
		else if(c<=12&&c>=11){
			if(a[2]-a[1]>=d) cout<<0<<'\n';
			else cout<<max(0ll,n-d/(a[2]-a[1])*2+1)<<'\n';
		}
	}
	return !"I'm xcb";
}
/*
第0步，下载考生手册，并仔细阅读。 [下载]（拜托，一定要仔细阅读）
第1步，下载试题包，并解压缩。 [下载]
第2步，用密码解密试题册。 试题册密码：Oct31==Dec25?
第3步，编程解答每道题目，并将源代码提交到系统。
第4步，查看已经提交的源代码，确认已经正确提交。
注意：程序中输入输出部分请严格按照试题册要求编写。

Rrhar'il
∅ ∅ ∅∅∅ ∅ ∅ ∅∅∅
∅∅ ∅ ∅∅∅ ∅∅ ∅ ∅∅∅
luogu 灌注 xcb 谢谢喵~

因为今天 K/F/C 非常便宜 20 块钱能买 15 个香菇鸡
K/F/C    好便宜



关于我用计算机换算出了 -300℃=-26.85K

7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

4557430888798830399
9223372036854775807

目前（不挂） 100+100+24


260000 1 7
699940 2857391858419 2857391858419
260000 14 7
260000 21 7
260000 606662 7
260000 1820001 7
10 31746031746031745 222222222222222215
10 222222222222222208 222222222222222208
10 14 7
10 21 7
10 22 7
10 1999999999999999970 199999999999999997

0
0
259997
259995
86669
0
0
0
7
5
5
0

*/