//考号：SN-J00758 姓名：张洛菡 学校：西安市第八中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Info {
	int id;
	char c;
} q[500001];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int qwq=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>q[i].id>>q[i].c;
		qwq+=q[i].id;
	}
	stack<Info> stpmc;
	deque<Info> stpmc1;
	stack<Info> stpmc2;
	int x=0,y=0;
	bool jump_mid=0;
	for(int i=1; i<=n; i++) {
		if(x+q[i].id>(qwq/2)) {
			stpmc1.push_back({qwq/2-x,q[i].c});
			stpmc2.push({q[i].id-(qwq/2-x),q[i].c});
			jump_mid=1;
			y=qwq/2-x;
		}
		if(!jump_mid) {
			stpmc1.push_back({q[i].id,q[i].c});
			x+=q[i].id;
		} else {
			stpmc2.push({q[i].id,q[i].c});
		}
	}
	
//	cout<<y<<endl;
//	cout<<stpmc1.size()<<endl;
	int ans=0;
	while(!stpmc1.empty()) {
		if(stpmc1.front().id>stpmc2.top().id) {
			if(stpmc1.front().c!=stpmc2.top().c) {
				stpmc1.front().id -= stpmc2.top().id;
				ans+=stpmc2.top().id;
				stpmc2.pop();
			} else {
				stpmc1.front().id -= stpmc2.top().id;
				stpmc2.pop();
			}
		} else {
			if(stpmc1.front().c!=stpmc2.top().c) {
				stpmc2.top().id -= stpmc1.front().id;
				ans+=stpmc1.front().id;
				stpmc1.pop_front();
			} else {
				stpmc2.top().id -= stpmc1.back().id;
				stpmc1.pop_front();
			}
		}
	}
	cout<<ans<<' ';

}
//心情大好
//预估100+100+100+0
//够了
//J拿个5√保底得了
//别挂分qwq，我真求你了awa
