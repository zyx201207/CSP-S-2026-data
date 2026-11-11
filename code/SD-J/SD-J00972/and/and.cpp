#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans=0,sum=0x7fffffff,a[N];
void dfs(int x,int y,int t){
	if(n-x+1<m-y) return;
	if(t<ans) return;
	if(y==m){
		ans=max(t,ans);
		return;
	}
	if(x==n+1) return;
	dfs(x+1,y+1,t&a[x]);
	dfs(x+1,y,t);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum&=a[i];
	}
	if(m==n) ans=sum;
	else if(m==1) ans=*max_element(a+1,a+n+1);
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]<ans) break;
				if(a[j]<ans) break;
				if(i==j) continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
	}else dfs(0,0,0x7fffffff);//不行?那毁灭吧!
	printf("%d",ans);
	return 0;
}
/*
Minecraft NeoForge Loading...
Minecraft Best!
Minecraft:Create
(机动玩家)
PCL2
呜呜呜,PCL的下载功能...
龙猫我支持你!!!
冈易你怎么不敢举报官方启动器?
怕麻将把你的Minecraft代理权收去?
Mojang NB!
Mojang NB!
龙猫我支持你!!!
Mojang万岁!!!
打压冈易!!!
为什么要举报下载!我花了89大洋呀!

冈易 does not have mother!
It's CS!
It's SB!

让我们辱骂冈易!!!

密码:Trick||Treat!
1933577

希望能J1,但不太可能。
那就J2吧。
T1:AC
T2:MLE 48pts
T3:TLE 40pts
T4:TLE 48pts
Total:236pts
*/
