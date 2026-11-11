#include<iostream>
#include<vector>
#include<deque>
#include<set>
using namespace std;
#define int long long
class game{
private:
	deque<int> dq;
	set<int> tbl;
public:
	void ins(int n){
		if(tbl.find(n)!=tbl.end())
			while(dq.back()!=n)
				tbl.erase(dq.back()),dq.pop_back();
		else
			dq.push_back(n),tbl.insert(n);
	}
	void clr(){tbl.clear(),dq.clear();}
	bool chk(int i){return tbl.find(i)!=tbl.end();}
};
signed main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	//freopen//freopen//freopen//freopen//freopen//freopen
	//啊哈哈哈诈骗真好玩
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<int> a(n),res(m+1,0);
	for(auto &i:a)
		cin>>i;
	for(int i=0;i<n;i++){
		game l;
		for(int j=i;j<n;j++)
			l.ins(a[j]);
		for(int j=1;j<=m;j++)
			if(l.chk(j))
				res[j]++;
	}
	for(int i=1;i<=m;i++)
		cout<<res[i]<<' ';
}
/*
显然我（！？区？！）是不会这道题的正解的（真区啊）
所以我将模拟游戏全过程（
10:37 呃啊啊难受啊写了半个多小时的链表发现是错的，悲
但是ccf出题好像比cwmx简单一些
而且都可以直接暴力或者模拟
（只是拿不到满分就是了）
赞美ccf
ccf i love u（
#4 8049ms 炸了QAQ，悲伤
看来1=无望了，就这样吧

注：我能进cspj奇人共赏吗
又注：关注pigeon4836谢谢喵awa

*/