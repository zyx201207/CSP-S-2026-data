#include<bits/stdc++.h>

using namespace std;
stack<int>st;
int vis[300005],a[500005],k[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int le=1;le<=n;le++){
		for(int i=le;i<=n;i++){
			if(vis[a[i]]!=1){
				st.push(a[i]);
				vis[a[i]]=1;
			}else{
				while(vis[a[i]]!=0){
					vis[st.top()]=0;
					st.pop();
				}
				st.push(a[i]);
				vis[a[i]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i]==1){
				k[i]++;
				vis[i]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<k[i]<<" ";
	}
	return 0;
}
/*
烦死了
不认真写题的下场
要AFO了
T2真的写不下去了，不知道为什么这个CCF出的数据要那么大
就不能放简单一点的吗？
也可能是自己技不如人吧
不过T4 48分还是可以的，至少部分分有了
不可以，我一定不能AFO，我一定要把第二题写出来！！！！！
原来有64分，那个电脑我不想说了记事本自动过滤换行
从来没有用过这么糟糕的电脑
总分封顶300，一等没希望了，二等可以冲冲 
好了，琢磨一下正解吧，反正第三题估计挂
T3只有特判的分qwq
qwqqwqqwq怎么办这个T2没木 
做不出来了，怎么办？就这个成绩了吗？
我不甘心啊，我学了这么久，就拿到了这个成绩？
OI的路很难走
我连解法都想不到啊
我感觉我对不起老师和父母 
哦豁，又骗来了8分，255分
心情大好
继续！100+72+35+48 
继续个屁，没有思路了
部分分全部拿到了
还有半个小时，怎么办啊
 
*/
