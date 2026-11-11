#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],p[N],ans[M];
vector<int> pos[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pos[a[i]].push_back(i);
		p[i]=pos[a[i]].size()-1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(p[j]+1<pos[a[j]].size()) j=pos[a[j]][p[j]+1];
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
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
