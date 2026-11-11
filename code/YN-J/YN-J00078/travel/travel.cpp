#include <iostream>
using namespace std;
struct nodddd{
	long long x;
	char s;
};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool num = true;
	long long a,c;
	nodddd b,d;
	cin>>a;
	cin>>b.x>>b.s;
	cin>>c;
	cin>>d.x>>d.s;
	if(a == c)
	{
		cout<<1;
	}
	else
	{
		num = false;
		cout<<0;
	}
	bool summ = true;
	if(b.x == d.x && num)
	{
		cout<<1;
	}
	else
	{
		summ = false;
		cout<<0;
	}
	bool ans = true;
	if(((b.s >= 'A' && b.s <= 'C') && (d.s >= 'A' && d.s <= 'C')) && summ)
	{
		cout<<1;
	}
	else if(((b.s >= 'D' && b.s <= 'F') && (d.s >= 'D' && d.s <= 'F')) && summ)
	{
		ans = false;
		cout<<1;
	}
	else
	{
		ans = false;
		cout<<0;
	}
	if(ans)
	{
		if(b.s + 1 == d.s || d.s + 1 == b.s)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		if((b.s == 'D' && d.s == 'F') || (b.s == 'F' && d.s == 'D'))
		{
			cout<<1;
		}
		else
		{
    		cout<<0;	
		}
	}
	return 0;
}
