#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
struct SB_kards{//别管这个名字
	int len;
	char c;
}a[maxn];
struct buhui_quming{//不会取名
	int now_i,n;//啊啊啊这个取名怎么这么难啊
}l,r;
int n;
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
	}
	l.now_i=1;l.n=1;
	r.now_i=n;r.n=a[n].len;
	while(l.now_i<r.now_i||(l.now_i==r.now_i&&l.n<=r.n)){
		if(a[l.now_i].c!=a[r.now_i].c){
			ans++;
		}
		l.n++;r.n--;
		if(l.n>a[l.now_i].len){
			l.n=1;
			l.now_i++;
		}
		if(r.n<1){
			r.now_i--;
			r.n=a[r.now_i].len;
		}
	}
	printf("%lld",ans);
}
/*
好吧，我已经期待这一刻很久了：
phigros第九章很好玩！！！！！
看看T3/T4有没有时间闲聊吧
我有个62的思路
你说我以后会不会在自己的学校考CSP？
666已经开赛1h了
T2都不会我是不是可以重开了
OK啊，目前162
#1 in
3
2 a
2 b
1 c
#1 out
2
#2 in
2
2 a
3 a
#2 out
0
#3 in
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
#3 out
3000000000
*/
