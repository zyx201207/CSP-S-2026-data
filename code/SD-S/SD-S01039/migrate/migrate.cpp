//16:20 I'm coming! I waste too much time on T2 for getting [0,24]pts,so I should get more pts in T3.
//		怎么多测啊，还有 2e6 是什么鬼 
//16:34 没分可骗，去 T4 
//17:21 T4 没骗到分，回来了 
//		I'm so upset now. When I got 100pts in T1, I felt excited. But I got 0 pts in T2-4.
//17:49 乱搞了 8pts 
//		毁灭吧，提高组只有 [108,132]pts 
//		T1 is easy for everyone, so can I get 2=?
#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int x[2000005];
int cnt[305][305][305];//从 i 到 j 长度为 k 的路径数量 
void dfs(int s,int u,int res){
	for(int i=u+1;i<=n;i++){
		if(x[i]-x[u]>d)break;
		cnt[s][i][res+1]++;
		dfs(s,i,res+1);
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=0;k<=n;k++)cnt[i][j][k]=0;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int s=1;s<=n;s++)
		dfs(s,s,0);
	int ans=0;
//	cerr<<"ST...\n";
	for(int s=1;s<=n;s++){
		for(int t=s+1;t<=n;t++){
			for(int k=0;k<=n;k++){
				if(cnt[s][t][k]!=0&&cnt[s][t][k]!=2)break;
				if(cnt[s][t][k]==2){
					ans++;
//					cerr<<s<<' '<<t<<' '<<k<<'\n';
					break;
				}
			}
		}
	}
//	cerr<<"ans=";
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0;
} 
/*
0 1
5 2
1 2 3 4 5

2
*/
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1
*/
//8pts 
