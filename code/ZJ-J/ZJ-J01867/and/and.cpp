#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#define int long long
int n,m;
vector<int> a;
int dfs(int now,int val,int dep){
	if(now>=n)
		return val;
	if(dep==m-1)
		return val;
	int res=-1;
	for(int i=now+1;i<n;i++)
		res=max(res,dfs(i,val&a[i],dep+1));
	return res;
}
signed main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;
	a.resize(n);
	for(auto &i:a)
		cin>>i;
	int res=-1;
	for(int i=0;i+m<n;i++)
		res=max(res,dfs(i,a[i],0));
	cout<<res;
}
/*
显然是一个dp
于是考虑设计状态
时限1000ms，数据2e5
靠，摆了，发现自己根本不会dp 
and操作满足结合率
也就是说a&(b&c)==(a&b)&c
那么能不能利用一些神奇的数据结构来解决呢 
或者说要根据一些神奇的方法来排序？ 
不行，直接暴力深搜（ 
OK暴搜写好了，看看能过哪些数据（其实是测试有没有写对） 
看起来只能通过前三个样例
暴搜太慢了，能不能进行一些剪枝呢 
记忆化！
但是记忆化貌似不是一个好主意...
得了，就这样吧 
*/
