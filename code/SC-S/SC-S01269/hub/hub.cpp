#include<bits/stdc++.h>
using namespace std;
int main(int argc,const char *argv[]){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
		int seed=1;
		if(argc>1) seed=atoi(argv[1]);
		srand(time(0)*2/3%198+seed*17);
		int c,t;
		cin>>c>>t;
		while(t--){
			int n,k;
			cin>>n>>k;
			int u,v;
			for(int i=1;i<=n-1;i++){
				cin>>u>>v;
			}
			n-=n*(n>10)/2;
			int thisisacorrectanswer;
			while(10)
			thisisacorrectanswer=rand()%n+1;
			cout<<thisisacorrectanswer<<endl;
		}
	return 0;
}
/*LGID ：myubi又来了
早上本来还想看S组能不能暴力抢分的
现在看只有T1是我勉强能暴的，吓哭了
还有两个半小时
现在T2 T3 T4都不会做，想着看看特殊性质偷分的
但感觉给了又没给 气笑了
实在没思路
写个随机数吧
ok也是写完了，一不小心三道题都写了随机(绷) 
让我想想有没有什么能干的事
emmm........
LG的站友们好啊(应该是能上奇葩大赏的吧)
现在总结一下今天干了一些什么事，算是写了一篇游记吧 
早上6:00起床吃饭，出门等滴滴，今天司机迟到了五六分钟 
到学校差不多6:40的样子，看了一下注意事项和可能爆零的地方
发现好像没有我前两次莫名其妙有爆零的原因，这就是被爆零恶魔诅咒之人吗
7:00左右出发了，学校租的车还是那么闷，看着一起来的初中学弟学妹们
好像也看不到我的影子，可能是因为他们不会爆零吧，也可能是还没出太阳，影子还不明显 
说到初中，虽然我高中和初中是同一所学校，也有一些原来班上的人在年级上 
但是总感觉上了高中后，不在一个班上总是像隔着一层膜一样
又偏题哩 
到了比赛教室里后，感觉就和前几次一样，但害怕又爆零力
整体做下来感觉还可以，T4还是没能拿下
中午老师带我们出去吃自助，可惜@Asoccia没来
好像是前年吧
我们也是去吃的烤肉自助，当时我和Asoccia还有moku(两个兄弟说是)在里面炒肉没绷住
现在一个去了八中，一个在我们学校另一个班上
有点想念就是哩 
自助吃完 感觉有点晕碳（烤肉烤成碳板了说是）， 头有点胀胀的 
到教室已经无法独立思考了-----myubi停止了思考
看完S组的题，本来说T1和T3都可以拿一些部分分的，但T3写着写着打了个哈欠就断片了
现在的情况就是纯运了，运气好就300，运气一般就不到100
一念神魔之人说是 
 
怎么还有两个小时啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
不知道该干什么了
打打表吧

搞了个数字炸弹玩
#include<bits/stdc++.h>
using namespace std;
bool op;
void solve(int l,int r,int k,int x){
	if(k<x){
		cout<<"现范围："<<k<<"---"<<r<<endl;
		l=k;
		op=1;
	}
	else{
		cout<<"现范围："<<l<<"---"<<k<<endl;
		r=k;
		op=0;
	}
	return;
}
int main(int argc,const char *argv[]){
	int seed=1;
	if(argc>1) seed=atoi(argv[1]);
	srand(time(0)+seed*7);
	cout<<"-----------按y开始-----------"<<endl;
	char c;
	cin>>c;
	while(c=='y'){
		int cnt=0;
		int ru,l,r;
		cout<<"输入范围：";
		cin>>l>>r;
		int x=rand()%(r-l-1)+1+l;//炸弹 
		bool f=1;
		while(f){
			int k=rand()%(r-l)+l;
			while(k==r||k==l) 
				k=rand()%(r-l)+l;
			cout<<"我选"<<k<<"喵"<<endl; 
			if(k==x){
				cout<<"炸弹竟然是"<<x<<"喵"<<endl;
				cout<<"不服，再来喵!"<<endl;
				cout<<"-----------按y开始-----------"<<endl;
				cin>>c;
				break;
			}
			else{
				solve(l,r,k,x);
				if(op) l=k;
				else r=k;
				cout<<"快点喵，该你了"<<endl;
				cin>>ru;
				while(ru>=r||ru<=l){
					if(cnt==0){
						cout<<"不能输出这以外的数字喵"<<endl;
					}
					if(cnt==1){
						cout<<"都说了不能输外面的喵"<<endl;
					}
					if(cnt==2){
						cout<<"再不听话我就生气哩"<<endl ;
					}
					if(cnt==3){
						cout<<"你违反了规则喵"<<endl;
						 cout<<"-----------按y开始-----------"<<endl;
						cin>>c;
						break;
					}
					cnt++;
					cin>>ru;
				}
				if(ru==x){
					cout<<"输了吧砸库(ノへ￣、),我可是不可战胜的喵"<<endl;
					cout<<"-----------按y开始-----------"<<endl;
					cin>>c;
					break;
				}
				solve(l,r,ru,x);
				if(op) l=ru;
				else r=ru;
			}
		}
	}
	return 0;
}


还有40分钟，这下是真不知道该干什么了
外面已经有点黑了
窗外........
............
............
............
窗外的天气  	    	在茈诞生的前41秒 
就像是					新宿上空响起了五条悟的吟唱... 
你多变的表情  			九冈 天光 屋与声明 表里之间(bushi)
下雨了  雨陪我哭泣
看不清
我也不想看清
离开你我安静的抽离
不忍揭晓的剧情
我的爱留在心里
学会放弃~~~
听雨的声音 一滴滴清晰
你的呼吸像雨滴渗入我的爱里
只希望雨能下不停
让想念继续 让爱能延续
阿巴阿巴阿巴阿巴阿巴阿巴阿巴阿巴阿巴阿巴阿巴阿巴阿巴阿巴阿巴阿巴阿巴 
18:00 了
只要再等半个小时，就宣布胜利吧（yagami音） 
只要...能到达那个时间 啊老八宵夜(dio音) 
话说
最近在追进巨，看到兽巨，铠巨和超巨包围调查兵团的部分了
为什么他们说艾伦是个阴呢，不是只会叫，硬质化和挥拳吗 
还有就是jo7感觉每集都好短啊，不够看有没有懂的 
*/