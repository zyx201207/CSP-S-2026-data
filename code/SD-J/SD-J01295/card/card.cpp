#include"bits/stdc++.h"
using namespace std;

/*
把其看作一个栈
当放入一个值时，如果栈内有该元素
一直弹出栈顶，直到该元素
最后统计栈内剩余元素 
这样我们可以在 $O(n^2)$ 的复杂度下完成模拟（？
期望得分：4*12=48pts 
性质 A 的意思是只可能相邻两个牌（？）咯
这样好像又能有 4pts 了
期望得分：4*12+[0,4]=[48,52]pts 
*/ 
const int MAXN=1e5*5+5;
int a[MAXN],cnt[MAXN];
bool vis[MAXN]; 
int n,m;
bool flag_A=1;
stack<int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<a[i-1])flag_A=0;
	}
	if(flag_A==1){
		//每个元素相当于前面的元素之和 + 本身
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			cnt[i]+=cnt[i-1];
			printf("%d ",cnt[i]);
		}
//		cerr<<"yes,is data A\n";
		return 0;
	}
	for(int k=1;k<=n;k++){
		while(!st.empty())st.pop();
		for(int i=k;i<=n;i++){
			if(vis[a[i]]){
				//栈内有元素
				while(!st.empty()){
					int t=st.top();
					st.pop();
					vis[t]=0;
					if(t==a[i])break;
				} 
			}
			st.push(a[i]);//加入
			vis[a[i]]=1;
		}
		for(int i=1;i<=m;i++){
			if(vis[i])cnt[i]++;
			vis[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
?-11:10
*/
