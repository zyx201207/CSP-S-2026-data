#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(int x,int y)
{
	return (x<3&&y<3&&abs(x-y)==1)||(x>=3&&y>=3&&(x==3&&y==5||x==5&&y==3));
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int id=(int)(s1[2]-'A');
	int id2=(int)(s2[2]-'A');
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&((id<3&&id2<3)||(id>=3&&id2>=3)))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&((id<3&&id2<3)||(id>=3&&id2>=3))&&check(id,id2))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
