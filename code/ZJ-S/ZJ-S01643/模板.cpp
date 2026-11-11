#include <bits/stdc++.h>

using namespace std;

#define gc() getchar()
#define pc(x) putchar(x)

int read()
{
	int x=0,f=1;
	char c=gc();
	while(!isdigit(c)) {if(c=='-') {f=-f;}c=gc();}
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=gc();
	}
	return x*f;
}

void write(int x)
{
	if(x<0) {pc('-');x=-x;}
	if(x<10) {pc(x+'0');return ;}
	write(x/10);pc(x%10+'0');
	return ;
}

void print(int x)
{
	write(x);pc('\n');
	return ;
}


int main()
{
	//~ freopen("","r",stdin);
	//~ freopen("","w",stdout);
	auto T1=clock();
	
	
	auto T2=clock();
	cerr<<(T2-T1)*1.00/CLOCKS_PER_SEC;
	return 0;
}
