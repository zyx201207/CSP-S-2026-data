#include<bits/stdc++.h>
#define int long long

using namespace std;
inline int fr(){
	int k=1,s=0;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s;
}
//这是什么玩意 
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);

	return 0;
}
/*
放弃了，这道题目，总结一下吧

 T1 过于水 ，二分答案加道路修复
 T2 是食，谁能想到是强连通分量加上一个Floyd，还有各种奇奇怪怪的小文件
 不过调了一个半小时 ，最终还是调出来了
 
 省一已经毫无悬念，除非文件什么的写错了，但我看着并没有
 
 为我的信息学奥赛生涯鼓掌！！
  
 this is the beginning ,and have yet to be a ending.
 
 就这样 ending 不大可能了 
 
 NOIP，2026 加油！！！ 
*/ 
