#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2){
		cout<<1;
		if(c1[0]==c2[0]&&c1[1]==c2[1]){
			cout<<1;
			if((
			(c1[2]=='A'||c1[2]=='B'||c1[2]=='C')
			&&(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'))||
			((c1[2]=='D'||c1[2]=='F')
			&&(c2[2]=='D'||c2[2]=='F'))){
				cout<<1;
				if(c1[2]>c2[2]) swap(c1[2],c2[2]);
				if((c1[2]=='A'&&c2[2]=='B')
				||(c1[2]=='B'&&c2[2]=='C')
				||(c1[2]=='D'&&c2[2]=='F')) cout<<1;
				else cout<<0;
			}else cout<<0<<0;
		}else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
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
