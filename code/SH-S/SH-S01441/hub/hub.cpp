#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=1e5+8;
int read()
{
	int base=0,sign=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') sign=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		base=(base<<3)+(base<<1)+ch-'0';
		ch=getchar();
	}
	return base*sign;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w".stdout);
	int a=read();
	cout<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
