#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;	
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	//s zuo
	//c 
cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&c1!="01"&&c1!="16"&&c2!="01"&&c2!="16")
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(c1==c2&&c1!="01"&&c1!="16"&&c2!="01"&&c2!="16"&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
    if(c1==c2&&c1!="01"&&c1!="16"&&c2!="01"&&c2!="16"&&s1[0]==s2[0]&&s1[1]==s2[1]&&s1<"C"&&s2<"C"){
    	cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(s1=="A"&&s2=="B"||s1=="B"&&s2=="C"||s1=="D"&&s2=="F")
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
