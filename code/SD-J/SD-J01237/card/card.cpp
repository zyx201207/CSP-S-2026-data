#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m,a[500010],ans[300010];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool vis[300010]={0};
		stack<int> st;
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				st.push(a[j]);
				vis[a[j]]=1;
			}
			else{
				while(st.top()!=a[j]&&!st.empty()){
					vis[st.top()]=0;
					st.pop();
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
/*
肥美的48部分分 

9:55 card? kards!
|---------------------------|
|                           |
|                           |
|          \|||||/          |
|           |o o|           |
|           | - |           |
|             #             |
|          #######          |
|          #GUMMI#          |
|          #######          |
|           -----           |
|----------|  !  |----------|
|           -----           |
|          冰岛人           |
|  把服务器变成土豆并吃掉   |
|            [#]            |
|---------------------------|
11:00 O(n^2)完成 

沟槽的美芬

回家第一件事
打开卡兹jjc
150金币一次
我非常癫狂
德国主国
法国盟国
三张撤退坦克
还有俯冲懵逼哥
谁能如何我
正在寻找敌人
wc完蛋
是沟槽的美芬
起手131伏击
这把也许有的办
希望对面手牌烂
什么T26、466、还有蓝灰师
硬头皮交换撑后期
我还有俾斯麦兜底
什么惩戒逃离斩杀线
沟槽的激怒
沟槽的美芬
沟槽的冰岛人

1939工作室
快让美芬414
不然我就曼哈顿
你的工作室 

11:07 默写完成 

luogu:congcong2012 
希望能上迷惑行为大赏 
*/
