#include <iostream>
using namespace std;
int a,n[100001],m,l,mx,kj,iop = 1;
char c[100001];
string s;
bool qwe()
{
	for(int i = 0;i < a;i++)
	{
		int j = l + 1 - i;
		if(s[i] == s[j])
		{
			
		}
		else
		{
			return false;
		}
	}
	return true;
}
bool uio(int you)
{
	for(int ki = 1;ki <= a;ki++)
	{
		
	}
}
int jkl()
{
	for(int i = 10000;i >= 1;i++)
	{
		if(uio(i))
		{
			return i;
		}
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> a;
	for(int i = 1;i <= a;i++)
	{
		cin >> n[i] >> c[i];
		if(mx < n[i])
		{
			kj = i;
			mx = n[i];
		}
		l += n[i];
	}
	if(a == 1)
	{
		cout << 0;
	 } 
	if(l >= 1000000000)
	{
		for(;;)
		{
			int op = jkl();
			if(op == 1)
			{
				break;
			}
			else
			{
				for(int p = 1;p <= a;p++)
				{
					n[p] /= op;
				}
				iop *= op;
			}
		}
	 } 
	 for(int i = 1;i <= a;i++)
	 {
	 	for(int j = 1;j <= n[i];j++)
	 	{
	 		s += c[i];
		 }
	 }
	if(qwe())
	{
		cout << 0;
		return 0;
	}
	for(int i = 0;i < l;i++)
	{
		int j = l - 1 - i;
		if(s[i] == s[j])
		{
			m++;
		}
	}
	if(l % 2 == 0)
	{
		cout << ( l - m * 2 ) / 2 * iop;
	}
	else
	{
		cout << (l - m * 2 + 1) / 2 * iop;
	}
	return 0;
 } 
 
