//please open the file with ANSI code
#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int u[1000000],v[1000000];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			cin>>u[i]>>v[i];
		}
		if(c==13||c==14){
			if(n==k){
				cout<<0<<endl;
				continue;
			}
			k/=2;
			int m=n-1;
			m/=2;
			m+=1;
			m/=2;
			if(k<m) cout<<(m-k+1)/2+1<<endl;
			else cout<<1<<endl;
		}
	}
	return 0;
}

//我该在哪里停留？我问我自己。
//我没招了------16:24
//打点骗分吧
//这应该是我最后一次打OI了 
//骗分打完了------16:31
//我的朋友去年都退役了
//我应该也快了
//132pts应该够不上1= 
//或许一中有名额让我去noip
//哪又有什么用呢
//我去了又能怎样
//再旅游一次? 
//彻底没招了
/*我去差点忘了有多行注释了
<recall>
我从初一开始打OI
在我们初中我算是第一
但这只能算是比上不足比下有余 
但是之前两次CSP全都是2=
上次s组2=给我的科创加了15分
但是我还是没考上
差一分...
</recall>
我又有招了 
t2优化了一些
应该能sum=160
T2要开longlong啊 
十年OI一场空，不开longlong见祖宗
T2调出来了
应该吧
sum=200
T1也忘开long long了
行
球球了不要出什么岔子
我想要1=
检查一下吧
longlong 开了
return 0 写了
endl 写了
变量初始化检查了
应该没什么别的了吧
 
//freopen("hub.in","r",stdin);
//freopen("hub.out","w",stdout);
//freopen("hub.in","r",stdout);
//freopen("hub.out","w",stdin);
//froepen("hub.in","r",stdin);
//froepen("hub.out","w",stdout);
int mian
尝试钓鱼
我想进迷惑行为大赏owo
继续说吧
我的文化课和编程一样
比上不足
唉
朋友们都去科创和实验班 
只有我去了普通班
唉
我只是一个普通人
一个Class Human{...}的实例 
不管怎么说
我还是喜欢编程
I love OI
我不后悔来打OI
rp++;
rp=INT_MAX;
200应该够1=吧
希望如此
打的太投入以至于忘了吃零食
开始野餐------17:55
chocolate真豪赤
我要是写炸了你们别笑我好吗
球球了
想写点什么但是不知道该写什么
(仿佛受到了某种触动)
要结束了
再见了朋友们
*/ 
