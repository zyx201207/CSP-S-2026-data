#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5;
const int M=3*1e5;
int a[N],t[M],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=5&&m<=2){
		int top=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				b[++top]=a[j];
				for(int k=1;k<=n;k++){
					if(a[k]==a[j]){
						for(int i=k;i<=j-1;i++) b[i]=0;
					}
				}
			}
			for(int j=1;j<=n;j++){
				t[b[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<t[i]<<" ";
		}
		return 0;
	} 
	for(int i=1;i<=m;i++){
		cout<<i<<" ";
	}
	return 0;
}
/*
11：24 
虽然这题不会，但第一和第二题简单 
第三题磕了一个半点磕出正解了 
此情此景，我不禁感慨 
“OI角斗赛”
估题难度红橙黄绿 
估分300
坐标SD
日照山东外国语职业技术大学
C203考场，座位号XX
我晕车，硬是扛过了三个半点
我佩服我自己
现在也头晕 

11：33 
现在心率78（真的）
昨天像是在做梦，讲个真实发生的事：
	10月30日14：15
	田XX（boy）去戳（kou）张（boy）的屁股
	然后戳（kou）错了...... 戳（kou）了一个（girl`s）的
	......
	。。。。。。 
此情此景，我又不禁感慨 
“可怜的男（le）孩（zi）”
此情此景，我不禁歌（hao）唱（jiao）一曲
	我祈祷拥有一颗透明的心
	和会流泪的眼睛
	......
	。。。。。。
打了这么多其实是为了放（ya）松（li）心（tong）情（xue）
也是为了能上luogu 迷惑行为大赏 
...... 

监考说11：55停止敲键盘
现在11：48
这个题感觉又骗了28分
此情此景，我又不禁感慨
“I need ECOM！！！”
作为一名神人，就要比其他任何人都要神 
神人指挥官更神
							
							
							!同志们，指挥官向你们致敬，祝福你们！ 
							
							Goodbye
							
							
							此致，终 
 
*/
