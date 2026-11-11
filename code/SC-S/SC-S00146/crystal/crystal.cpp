#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll sjsl,kczcs,a[500010],b[500010],cishu,sum=0,l=1,c=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//窝要上洛谷迷惑行为大赏（真 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//我要打舞萌！ 
	cin>>sjsl>>kczcs;
	//我要打中二！
	for(int i=1;i<=sjsl;i++){
		cin>>a[i];
	}
	//Welcome to maimai!
	sort(a+1,a+1+sjsl);
	//哦耶耶 桃花~谢了有玫瑰~ 
	for(int i=1;i<=sjsl;i++){
		b[i]=a[i]-a[i-1];
	}
	//Only feels like nothing could be better when I with you~(When I with you~)
	for(int i=1;i<=sjsl;i++){
		c+=b[i];
		sum+=(i-l+1)*b[i];
		while(sum>kczcs){
			sum-=c;
			c-=b[l];
			l++;
		}
	//X X XXX
	//x x xxx 
	//X X X XXX
	//x x x xxx
	//X X X XXXX
	//x x x xxxx
	//XX XX XXX XX
	//xx xx xxx xx 
		if(sum<=kczcs){
		cishu=max(cishu,i-l+1);
		}
	}
    //为什么监考老师不让睡觉（悲 
    //这个T4到底是啥玩意 
	cout<<cishu+1;
	return 0;
}