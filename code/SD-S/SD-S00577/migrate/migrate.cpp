#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2001000],dp[2001000],dis[2001000]; 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c==11||c==12){//A
		}
		if(c==13||c==14){//B
			
		} 
		if(c==15||c==16||c==17||c==18){//C
			
		} 
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dp[j]=0,dis[j]=1e18;
			dis[i]=0;
			dp[i]=1;
			for(int j=i+1;j<=n;j++)
				for(int k=j-1;k>=i;k--){
					if(x[j]-x[k]>d)break;
					if(dis[j]>dis[k]+1){
						dis[j]=dis[k]+1;
						dp[j]=dp[k];
					}else if(dis[j]==dis[k]+1)dp[j]+=dp[k];
					if(dp[j]>3)dp[j]=3;
				}
			for(int j=i;j<=n;j++)
				if(dp[j]==2)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
15:39 发现如果有路径，则一定是y单调递增
若(u,v)是双径岛屿对，则u,u+1,...,v是一个合法的路径，且其中恰有一点i(i!=u且i!=v)，使得i-1->i+1合法
我们可以找到所有这样的点i
15:45 我去长度是交换次数啊，重新思考
15:46 如果有路径，则一定是y单调递增这个结论可取 
15:55 刚上了个厕所，想出来了个东西：
若(u,v)是双径岛屿对，则u,u+1,...,v是一个合法的路径，且其中恰有一点i(i!=u且i!=v且i!=v-1)，使得i-1->i+1,i->i+2均合法
证明：
若存在大于等于3的跨越而不存在2的跨越，则：
i->i+1->i+2->i+4和i->i+2->i+3->i+4可推出i->i+1->i+3->i+4（存疑）
1 2 2+1e9 2+2e9 3+2e9
好吧结论错误 
也许存在大于3的跨越就一定存在2的跨越了
i->i+1->i+2->i+5和i->i+3->i+4->i+5可推出i->i+2->i+3->i+5 
其实i->i+2->i+5和i->i+3->i+5更优
无法得出i->i+4和i+1->i+5
不对我在想什么啊 
这题或许DP更好一些
16:15 对于每一个开始，我们DP求出最短路径数，时间复杂度O(n^2)的，分数=40
特殊性质A可以直接数学计算，分数=48
不写代码，看D题
16:39 D 想到了15分，回来想C 
16:44 没思路了，写48分吧 
16:52 假了16分，写32分吧 
17:02 假了8分，写了24分 
17:40 做特殊性质B中 
18:01 不会骗分了 
*/

