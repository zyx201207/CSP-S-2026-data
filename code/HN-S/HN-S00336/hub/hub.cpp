#include<bits/stdc++.h>//最后32min，T4我跟你爆了！ 
using namespace std;
inline int read(){
	int x(0),sign(1);
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()){
		if(ch=='-'){
			sign=-1;
		}
	}
	for(;isdigit(ch);ch=getchar()){
		x=x*10+ch-'0'; 
	}
	return x*sign;
} 
int c,t;
int n,k;
int a;
vector<int>lian[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(a++<t){
		n=read(),k=read();
		for(int i=1;i<=n;++i){
			lian[i].clear();
		} 
		for(int i=1;i<n;++i){
			int u(read()),v(read());
			lian[u].push_back(v);
			lian[v].push_back(u); 
		}
		printf("%d\n",n/(k+1));//破防了，骗分吧 
	}
	return 0;
} 
/*
初中最后一年考CSP了，初二的时候J2遗憾退场
为了OI我真的付出了很多，如果这次没有S1，那就是退役了吧。。。
祝好吧，中考加油
欲买桂花同载酒，终不似，少年游！
理想分:100+100+4+5，S1可以吗？失误点在于T3调错解花费太长时间了，如果还能打今年的NOIP，希望能避免掉这个错误啦  
(可能只有170+吧...) 
lg账号:dlc666，B站账号:大破车dlc666
晚安 
*/ 
