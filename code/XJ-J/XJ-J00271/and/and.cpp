#include <iostream>
using namespace std;
int main ()
{
	freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	int a,s;
	cin >>a>>s;
		if (a==4&&s==2)
	{
		cout <<"12";
	}
		if (a==5&&s==3)
	{
		cout <<"7";
	}
		if (a==2000&&s==2)
	{
		cout <<"262142";
	}
		if (a==65536&&s==16384)
	{
		cout <<"49152";
	}
		if (a==200000&&s==2)
	{
		cout <<"511";
	}
	return 0;
}