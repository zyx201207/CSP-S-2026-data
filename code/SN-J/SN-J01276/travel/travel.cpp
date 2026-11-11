#include<bits/stdc++.h>
using namespace std;
string s,s1,c,c1;
int a=0,b=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>c>>c1;
	//车厢 
	if(s==c) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	//排 
	if(s1[0]==c1[0]&&s1[1]==c1[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	//同侧 
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') a++;
	else b++; 
	if(c1[2]=='A'||c1[2]=='B'||c1[2]=='C') a++;
	else b++;
	if(b==2){
		cout<<"11";
		return 0;
	}
	else if(a==2){
		//相邻 
		cout<<"1";
		if(s1[2]=='A'&&c1[2]=='B') cout<<"1";
		else if(s1[2]=='B'&&(c1[2]=='A'||c1[2]=='C')) cout<<"1";
		else if(s1[2]=='C'&&c1[2]=='B') cout<<"1";
		else cout<<"0"; 
	}
	else cout<<"00";
	return 0;
}
//我清楚的知道，人与人之间的道路都是不可复制的，
//我走在属于我自己的人生的道路上，
//哪怕路途风雨再大，大到我步履维艰，
//哪怕荆棘丛生，刺得我伤痕遍体，
//我仍旧痴痴笑笑，体会其中苦乐，
//我相信终有一天，会两岸青山，虫鸟同鸣 
