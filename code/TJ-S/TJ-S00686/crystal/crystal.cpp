#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m; 
int a[500010],s[500010];
int res;
bool check(int mid,int i){return (((mid-i+1)*a[mid])-(s[mid]-s[i-1]))<=m;}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		for(;l<r;){
			int mid=(l+r+1)/2;
			if(check(mid,i))l=mid;
			else r=mid-1;
		}
		res=max(res,l-i+1);
	}
	cout<<res;
}

/*
密码：Otc31==Dec25?

30min，终于想出来T1是二分，开写

考场电脑打开文件好慢好慢。。。

强烈谴责，我要半分钟才能打开文件

原来能拖进dev啊、、、

T1写挂了，悲

怎么已经4点了

5点才发现自己T1先求前缀和再排序，不过好歹有个三位数分不是太难看了

但是T1大概率水橙，六勾混不上

T23都是图论吧，T3可能不是图论是DP之类的东西，T4也许是二分+？？？

都好难写，部分分难打，暴力没思路

感觉要打铁了

振作起来、、、

虚拟机密码是12345678 

5点半了，看看能不能把T2的特殊性质A or 朴素暴力打了

T2样例解释的的公式部分原来是错的

根本看不懂啊 : ( 
*/
