#include <bits/stdc++.h>
#define F(J) for(int j=1;j<=J;++j)
#define int long long
using namespace std;
/*
化学老师说过，你们这个阶段的题目，老想着一眼看出来怎么可能？
我想想啊
要求用m以内的操作次数（只能+1不能-1）凑出最多的相同元素 
注意特殊性质A和B 
都说的是 等差数列
对啊，又没说选择连续的！
那肯定先排序
然后呢
看看数据范围
longlong开得下 
观察到，N在5e5的范围
nlogn，想到二分
嗯，是不是每一次指定一个水晶作为基准值（不用已有的数字一定不优）
然后往前看看能让多少个水晶“同化”？
计算下时间复杂度
欸这不是二分吧
不管了看看
n个水晶遍历 n
每一次往前查找必须是logn
但是！
哦哦o我有思路了
先创建前缀和数组
然后用倍增的思想求！（这不还类似于二分吗awa 

等一下样例3不对好像
算了无视风险改成倍增 
OK表也是搞好了
坏了
算了
1h了先保存朴素写法别死磕 
不管了，有缘再见吧

我回来了
B题60分有了大概
A得AC
 
MD气笑了
原来是我排序前就前缀和了
来写倍增
 
 
我放弃倍增……拿60pts够了……
哎……断舍离吧，学会知足
You're at the Right Pace. 
*/
//long long mx=INT64_MAX; 9e18
int n,m,a[500500],pre[500500],stp[500500][22],ans=0;
int glen(int bgn,int ln,int sum,int ind){
	for(int i=0;(bgn-(1<<i)>=0);++i){//bgn还没被计算但bgn+1被计算了  i还没确定行不行 
		//cout<<"  ;\n";
		if((ln+(1<<i))*a[ind]-(sum+stp[bgn][i])>m){
			if(i){
				//cout<<"long"<<ln+(i<<i)<<" sum"<<sum+stp[bgn][i]<<" failed\n";
				//cout<<"Next: "<<bgn-(1<<(i-1))<<' '<<ln+(1<<(i-1))<<' '<<sum+stp[bgn][i-1]<<' '<<ind<<'\n';
				return glen(bgn-(1<<(i-1)),ln+(1<<(i-1)),sum+stp[bgn][i-1],ind);
			}return ln;
		}
	}return ln;
}
int fans/*find answer*/(int x){
	if(x-1){
		
			//先写朴素的
			int len=0;
			while(1){
				if(len==x){
					break;
				}if((len+1)*a[x]-(pre[x-1]-pre[x-2-len])>m){
					//cout<<"x="<<x<<" len="<<len+1<<"nds="<<(len+1)*a[x]-(pre[x-1]-pre[x-2-len])<<'\n';
					break;
				}++len;
				
			}return len;
		
		
		/*
		容我想想思路
		二分找？
		第一次找2^j，直到j+1大于了m
		然后以此为基础继续
		直到再扩大一格都会超
		递归再合适不过了 
		*/
		//return glen(x-1,0,0,x);
	}return 0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	F(n){
		cin>>a[j];
	}sort(a+1,a+n+1);
	F(n){
		pre[j]=pre[j-1]+a[j];
		stp[j][0]=a[j];
	}
	/*F(n) cout<<pre[j]<<' ';
	cout<<"--------\n"; */
	//stp[i][j]意义：第i-2^j+1位到i位的和 
	for(int j=1;j<=21;++j){
		for(int i=1;i<=n;++i){
			if((i-(1<<j))>=0){
				stp[i][j]=stp[i][j-1]+stp[i-(1<<(j-1))][j-1];
			}
		}
	} 
	/*
	for(int i=0;i<=20;++i){
		for(int j=0;j<=n;++j){
			cout<<stp[j][i]<<' ';
		}cout<<'\n';
	}*/
	for(int i=2;i<=n;++i){
		ans=max(ans,fans(i));
	}cout<<ans+1;
	return 0;
}

/*
7 20 6 0 4 120 100 -1 -5
*/
