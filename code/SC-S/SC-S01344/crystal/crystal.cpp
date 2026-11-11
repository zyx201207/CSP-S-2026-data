#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	int mid = n / 2 + (n % 2),ans = 0;
//	cout << mid;
	for(int i = mid - 1;i > 0;i--){
		if(m < a[mid] - a[i]) break;
		m -= a[mid] - a[i];
		ans++;
//		cout << i << " ";
	}
	for(int i = 1;i <= n;i++){
		if(a[i] == a[mid]){
//			cout << i << " ";
			ans++;
		}
	}
	cout << ans;
	return 0;
}
//Oct31==Dec25?(神密解压密码)(Dec25是NOIP的日子)
/*
以前我还能做一点，自从上了初二，跟退化了一样
烷氢八氮了
17:57了，只有等s了，感觉整个人被抽干了
估计要被单调队列了
这次打完了就去搞文化课
不然我中考怎么办啊
J组2=吧，1=没希望了
一想到t3t4看不懂，t2dji忘完做不起就完蛋了
比赛搞完了就轻松多了
早上的游记还历历在目，t2t3t4做不起
但是作为初二生，学习才是最重要的
所以竞赛还是先放一放，可能再也没有机会了吗？
好吧，我还是有机会的(高中(不大可能)||ICPC)
我初中的信竞就到此为止吧。。。
完

Luogu:__Dhc666__(不定期诈尸)
uid:?(谁会记这玩意)

距离考试结束：00:01:00
*/