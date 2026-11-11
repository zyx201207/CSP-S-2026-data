#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,ans="";
bool b(string A,string B)
{
	if(A=="A"&&B=="B")
		return 1;
	else if(A=="B"&&B=="A")
		return 1;
	else if(A=="B"&&B=="C")
		return 1;
	else if(A=="C"&&B=="B")
		return 1;
	else if(A=="D"&&B=="F")
		return 1;
	else if(A=="F"&&B=="D")
		return 1;
	else 
		return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)
		ans+="1";
	else
	{
		cout<<"0000";
			return 0;
	}
	string m="",z="",h="",w="";
	m+=(s2[0]+s2[1]);
	z+=(s4[0]+s4[1]);
	h+=s2[2];
	w+=s4[2];
	if(m==z)
		ans+="1";
	else
	{
		cout<<"1000";
		return 0;
	}
	if(h>="A"&&h<="C"&&w>="A"&&w<="C")
		ans+="1";
	else if(h>="D"&&h<="E"&&w>="D"&&w<="C")
		ans+="1";
	else
	{
		cout<<"1100";
		return  0;
	}
	if(b(w,h))
	{
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0; 
		
} 
