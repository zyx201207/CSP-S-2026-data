#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,a[500010],m,rem,ans; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = n;i;i--)a[i]-=a[1];
	for(int i = 1,j = 1;i<=n;i++){
		int need=(i-j)*(a[i]-a[i-1]);
		rem+=(a[i]-a[i-1]);
		int u=min(m,need);m-=u;need-=u;
		while(need>0){
			int u=min(rem-a[j],need);rem-=u;need-=u;
			if(need){
				rem=a[i];j++;
			}
		}
		if(rem==a[i])ans=max(ans,i-j+1);
		else ans=max(ans,i-j);
	}
	cout<<ans<<"\n";
} 

/*
先给自己约法三章

1.不要在考试时主动玩原神，也不要打到一半发现自己在玩原神
2.不要在考试时默写追忆，也不要背诵追忆的时候打扰到其他考生
3.不要因为自己写了这些而在考场上想这些，也不要憋笑，会绷不住

blog:
 
1.登录的时候发现密码打成原神账号密码了，绷住
2.准考证号打成SC-S00163了，绷住
3.打开edge，发现"在edge关闭的时候，你有已打开的项目->还原"，然后发现是j组试题
我要绷不住了
 
14:34 会t1了
14:38 会t2了，似乎比去年简单
先写t1吧。14:55通过所有大样例 
*/