#include<bits/stdc++.h>
#define int long long
using namespace std;
int che1,zuo1,che2,zuo2;
char z1,z2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>che1>>zuo1>>z1>>che2>>zuo2>>z2;
	if(che1==che2){
		cout<<1;
		if(zuo1==zuo2){
			cout<<1;
			if(((z1=='A'||z1=='B'||z1=='C') && (z2=='A'||z2=='B'||z2=='C')) || ((z1=='D'||z1=='F') && (z2=='D'||z2=='F'))){
				cout<<1;
				if(abs(z1-z2)==1 && (z1!='C' && z2!='C')){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00\n";
		}
		else{
			cout<<"000\n";
		}
	}else{
		cout<<"0000\n";
	}
	
	return 0;
}
//Trick||Treat! 
/*
T1只需要if-else就可以做，然后成功

T2没有任何思路，有了一个然后被假掉了
所以只能考虑还原字符串然后匹配回文 

T3发现好像按位与会取最小
所以排序取第m个
ok经过我的实验发现这个做法显然假
所以还是写暴力吧...（欸话说我这个赌狗代码和暴力哪个得分会更高） 

T4并没有正解思路，因为n<=5e5所以我的n^2做法是必然炸掉的
但是至少有部分分可以拿
在测大样例的时候发现第四个T了，对应到表中就大概有<=24pts 

希望有1= /bx/bx/bx
*/ 
