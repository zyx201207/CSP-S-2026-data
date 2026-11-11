#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int n,m;
int a[maxn];
int ans;
int s1[maxn],s2[maxn];
void dfs(int lv,int num,int now){
	if(lv==m){
		ans=max(num,ans);
		return ;
	}
	for(int i=now+1;i<=n;i++){
		dfs(lv+1,num&a[i],i);
	}
}
int power___(int dishu,int zhishu){//防重名
	//这点数据不用快速幂了
	int rv=1;
	for(int i=1;i<=zhishu;i++){
		rv*=dishu;
	}
	return rv;
}
bool has_A(){
	for(int i=1;i<=n;i++){
		bool flag=0;
		for(int j=1;j<=20;j++){
			if(a[i]==power___(2,j)-1){
				flag=1;
				break;
			}
		}
		if(flag==0)return 0;
	}
	return 1;
}
bool cmp(int _1939,int huanwo_zhanghao){//1939还我账号
	return _1939>huanwo_zhanghao;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){//面向骗分编程
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}
	else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
	}
	else if(m==n-1){
		s1[1]=a[1];s2[n]=a[n];
		for(int i=2;i<=n;i++){
			s1[i]=s1[i-1]&a[i];
			s2[n+1-i]=s2[n+2-i]&a[n+1-i];
		}
		ans=max(s1[n-1],s2[2]);
		for(int i=2;i<n;i++){
			ans=max(s1[i-1]&s2[i+1],ans);
		}
	}
	else if(has_A){
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++)ans=ans&a[i];
	}
	else{
		for(int i=1;i<=n;i++){
			dfs(1,a[i],i);
		}
	}
	printf("%d",ans);
}
/*
注意到我们可以暴力骗25
OK啊，时间还有2h，太好了
m=1和m=2也能搞掉
m=n也能搞掉
m=n-1也能搞掉
这样的话就有60了
豆包豆包，大脑疯狂播放Entrance to the chaos怎么办
诸位，有个坏消息：我的KARDS账号被封了（也不叫被封了吧）
反正就是我这两天是玩不了卡兹了（可以看B站上我的视频）
手：大脑，你说我们这样真的能上CSP-J迷惑行为大赏吗？
其实我冥冥之中有种正解的思路
我搞不懂我为什么喜欢用cin输入，却喜欢用printf输出
啊不对，n-1好像搞不掉
好像可以做掉，用前缀和思想
哇，我特殊性质A好像也可以做了
建议各位都去听《What do you want more than a happy ending》，因为真的好听
诶不对啊？等我一下？？？
不用等了，当我没说
嗯，估分227
#1 in
4 2
3 15 12 12
#1 out
12
#2 in
5 3
31 3 1 15 7
#2 out
7
*/
