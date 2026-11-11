#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";//不在同一车厢 
		return 0;
	}
	if(s1>s2)swap(s1,s2);
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";//不在同一排 
		return 0;
	}
	if(s1[2]<='C'&&s2[2]>'C'){
		cout<<"1100";//不在同一侧 
		return 0;
	}
	if(s1[2]=='A'&&s2[2]=='C'){
		cout<<"1110";//不相邻 
		return 0;
	}
	cout<<"1111";//坐到相邻位置了，恭喜 
	return 0;
}
/*
大家好啊，我是去年AK CSP-X的涂文烁，我要开始写游记了
8:10进入考场
8:20发现走错考场
8:21来到考场
8:30 开题，细节今天万圣节密码Trick||Treat! ，然后开始解压缩并准备，因为不能提前动鼠标和键盘吗 
8:40 T1水题秒了
8:48 写完代码，细节见注释 
剩余部分看T2代码 
*/
