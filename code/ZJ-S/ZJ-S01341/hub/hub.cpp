/*
已经为了变得更好去掉锋芒
一不小心成了你的倾诉对象
电话约在从前约会的地方
要陪你唱歌吃饭我结账
保持优良习惯
你说最近过得还算幸福美满
喝了几杯唱了几段你却哭了
想去安慰却不知什么立场
听你说话看你哭湿头发
我得到了惩罚
戒了烟我不习惯
没有你我怎么办
三年零一个礼拜
才学会怎么忍耐
你给过我的伤害
是没有一句责怪
戒了烟染上悲伤
我也不想 
*/ 
#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 1e6+5;

int c, t, n, k;

namespace subtask1{
	void main(){
		while(t--){
			cin>>n>>k;
			for(int i = 2, xxxxx, ooooo; i <= n; i++)cin>>xxxxx>>ooooo;
			if(k&1)cout<<(n-1)/2-(k-1)/2<<endl;
			else cout<<(n-1)/2-k/2<<endl;
		}
	}
}

/*
13 1
5 2
1 2
2 3
3 4 
4 5

*/

signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>c>>t;
	if(c == 13 || c == 14)return subtask1::main(), 0;
	return 0;
}

