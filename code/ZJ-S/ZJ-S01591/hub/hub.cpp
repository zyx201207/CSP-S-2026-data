#include<bits/stdc++.h>
#define ll long long
using namespace std;
int e[210000],t[210000];
int main(){//chai
	////////   ////////        |             |
	//    //   //   //         |             |
	//  //     // //      =====+=====   =====+=====
	/////      ///             |             |
	//  //     //              |             |
	//    //   //              |             |
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>e[i]>>t[i];
		}
		cout<<abs(T*c%n*k-n)<<endl;
	}
//让我们愉快的写一篇游记：
/*  我不是HZ人，考场在HZ，在10.30日用时2.5h到达。
	酒店不大，cookiebus(我们教练luoguID)在赛前2周时安排好了
	来到酒店已经是9:20了，我敲了一遍线段树和最短路就睡了（可恶居然不考（也可能是我没看出来）邪恶的T2看起来像温暖的最短路我却不会）
	早上考J我T1AC，T2都没推出性质，草草结束，预估228，祈祷有2=
	下午考ST1调了1h14m调出，其余T2空着T3乱写T4如上
	祈祷 J2=S2=
	不过好在不用今年就Away From OI
	完
*/
/*
	忘川彼岸
	红色彼岸花，花瓣遍地撒。
	谁会在乎她在哭泣啊？
	跪在佛千年，不见佛生怜
	佛若不渡，那就让我来渡
	一花一叶一菩提，轮回依旧是场迷。
	待那菩提落地，献上半生烟雨。
	削发入庙披袈裟，只求我佛能渡她。
	
	坏了，只会这么一点
	有错勿喷/bx/bx
*/
	return 0;
}