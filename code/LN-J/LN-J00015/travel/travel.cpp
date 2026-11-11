#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int chexiang(string c1,string c2)
{
	int a=1;
	if(c1!=c2)
	{
		a=0;
	}
	return a;
}
int tongpai(string s1,string s2)
{
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i])
		{
			return 0;
		}
	}
	return 1;
}
int xianglin(string s1,string s2)
{
	if((abs(s1-s2)==1)&&((!((s1[2]=="C")&&(s2[2]=="D")))||(!((s2[2]=="C")&&(s1[2]=="D")))))
	{
		return 1;
	} 
	return 0;
}
int tongce(string s1,string s2)
{
	if(xianglin(s1,s2)) return 1;
	if((s1[2]=="C")&&(s2[2]=="A"))
	{
		return 1;
	} 
	if((s2[2]=="C")&&(s1[2]=="A"))
	{
		return 1;
	} 
	return 0;
}
int main()
{
	cin>>c1>>s1>>c2>>s2;
	cout<<chexiang(c1,c2)<<tongpai(s1,s2)<<tongce(s1,s2)<<xianglin(s1,s2);
	return 0;
}
