/*
钟山风雨起苍黄，百万雄师过大江。

Congratulation on AKing CSP-J!!
（让我上迷惑行为大赏，please）
见正文（改的别的文，别骂我）


我曾经不止一次地想过， 
编程，到底是什么。 
我想啊，想啊 。
每一次，我想起编程这两个字， 
血管里，便奔腾着一股股热血；
眼底里，便激荡着一层层希望；
心里，便翻涌起一阵阵温柔的浪波……

编程是什么？

它是int，是long long，
是差分，是二分，
是ST表，是A*， 
是延绵起伏的前缀和，是一望无垠的平衡树！ 

编程是什么？

它是热血，是希望，
是屏幕里的AC，是完满的rating，
是熬夜在电脑前写出的猪国杀，
是暴力在困境中的光明救赎！ 

编程是什么？

它是图灵与冯·诺依曼的制造，
是迪杰斯特拉与佛洛依德的算法，
是我们先辈中那些最智慧的人的创造，
是我们最尊崇的大师们的劳绩！ 

编程是什么？

它是SPFA的牺牲，
是链式前向星的血，
它是一次次的失败，一次次的探索，
一次次的倒下，又一次次的奋起！ 

啊，编程！
它是一首唱不完的战歌，
一篇写不尽的战报， 
它是我们的祖先，和祖先的祖先从未探寻过的地方，
也是我们的子孙，和子孙的子孙赖以生存发展的地方。
让我们更多的了解编程的昨天，
也更加努力地建设编程的今天与明天！
未来属于编程！！
编程的未来属于青年！！

Chocolate is delicious!
*/
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[500005],cnt[500005],maxx=-0x3f3f3f3f3f3f3f3f,now,sum; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	now=a[1];
	ans[1]=1;
	cnt[1]=0;
	for(long long i=2;i<=n;i++){
		if((a[i]-now)*ans[i-1]+cnt[i-1]<=m){
			ans[i]=ans[i-1]+1;
			cnt[i]=(a[i]-now)*(ans[i]-1)+cnt[i-1];
		}else{
			ans[i]=i-ans[i-1];
			sum=0;
			while((a[i]-now)*(i-ans[i])+cnt[i-1]-sum>m){
				sum+=now-a[ans[i]];
				ans[i]++;
			}
			ans[i]=i-ans[i]+1;
			cnt[i]=(a[i]-now)*(ans[i]-1)+cnt[i-1]-sum;
		}
		now=a[i];
		maxx=max(maxx,ans[i]);
	}
	cout<<maxx;
	return 0;
}
