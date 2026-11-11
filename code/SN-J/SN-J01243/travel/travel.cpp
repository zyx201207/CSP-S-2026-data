#include<bits/stdc++.h>//...
using namespace std;
freopen("travel.in","r",stdin)
freopen("travel.out","w",stdout)
int main()
{
	string c1,s1,c2,s2;//要不用循环转成字符算了
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)//同车厢 
	{
		cout<<"1110";
	} 
	else
	{
		cout<<"0000";//得，不会做，骗点分 
	}
/*
	int s11[5],s22[5];
	for(int i=0;i<3;i++)
	{
		if(i<=1)
		{
			//std::string {aka std::basic_string<char>}//也不能这样std::string {aka std::basic_string<char>}' and 'const char [2] 
			//const char [2]
			//s11[i]=s1-"0";//不能这样转-no match for 'operator-' (operand types are 'std::string {aka std::basic_string<char>}' and 'const char [2]')
			//s22[i]=s2-"0";
		}
		else
		{
			s11[i]=s1-"A";
			s22[i]=s2-"A";
		}
	}
	if(s11[0]==s22[0] && s11[1]==s22[1])//同排 
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(s11[2]+s22[2]<=3 || s11[2]+s22[2]==8)//同侧 
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(s11[2]+s22[2]==1 || s11[2]+s22[2]==3 || s11[2]+s22[2]==8)//相邻 
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
*/
	return 0;
}
