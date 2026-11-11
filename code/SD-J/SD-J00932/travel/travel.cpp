#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<'1';
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<'1';
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'))
			{
				cout<<'1';
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
					cout<<'1';
				else
					cout<<'0';
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	return 0;
}
/*
洛谷上有个东西叫迷惑行为大赏，挺喜欢看的，今天来挑战上一下
上了的话@一下我（uid 1615028)
游记就不写了，太懒了
感觉今年要挂，T3T4都不会，上帝保佑
对了，下午S还有我哦 
目录：
T1 前言
T2 自我介绍 
T3 KARDS x OI 的diy
T4 放点歌给你们听 
*/ 
