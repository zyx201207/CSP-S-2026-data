#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool flag=1;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)flag=0;
	cout<<flag;
	string tmp1=s1.substr(0,2);
	string tmp2=s2.substr(0,2);
	if(tmp1!=tmp2)flag=0;
	cout<<flag;
	char a=s1[2],b=s2[2];
	if((a>='A'&&b>='A'&&a<='C'&&b<='C')||(a=='D'&&b=='F')||(a=='F'&&b<='D'))
	{
	}else flag=0;
	cout<<flag;
	if((int)a+1==(int)b||(int)b+1==(int)a||(a=='D'&&b=='F')||(a=='F'&&b<='D'))
	{
	}else flag=0;
	cout<<flag<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}