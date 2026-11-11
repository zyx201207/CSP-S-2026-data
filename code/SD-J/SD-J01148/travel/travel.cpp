#include <iostream>
#include <string>
using namespace std;
string c1,s1,c2,s2;
bool xianglin()
{
	char w,x;
	w=s1[2],x=s2[2];
	if(w>x)
		swap(w,x);
	bool b;
	if(w=='C')
		return 0;//w<x,因此当w=C时，两者不相邻 
	if(w!='D')//因为w不可能为F，C已排除，则W=A/B 
		b=(x-1==w);
	else//w为D时，x为F 
		b=(x-2==w);
	return b; 
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool b1=0,b2=0,b3=0,b4=0;
	b1=(c1==c2);//1
	b2=(b1&&s1[0]==s2[0]&&s1[1]==s2[1]);//2
	b3=(((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C'))&&b2);//3
	b4=(b3&&xianglin());//4
	cout<<b1<<b2<<b3<<b4;
	//做完了 
	return 0;
}
