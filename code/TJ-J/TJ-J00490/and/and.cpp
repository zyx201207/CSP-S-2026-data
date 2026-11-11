#include <bits/stdc++.h>
using namespace std;
int D=0,T=0;
stack <string> st1,st2;
queue <string> st3,st4;
string k;
string turn1 (int aa)
{
	for(int i=1; ;i++)
	{
		if(aa==0)
			break;
		k=aa%2;
		aa/=2;
	}
	return k;
}
string _and(string x,string y)
{
	for(int i=0;i<max(x,y);i++)
	{
		if(x>y)
		{
			for(int j=0;j<(x-y);j++)
				st2.push(0);
		}
		else
		{
			for(int j=0;j<=(y-x);j++)
			{
				st1.push(0);
			}
		}
		if(st1.top()!=st2.top())
			st3.push(0);
		else
		{
			st3.push('1');
		}
		b[i]=st3.front()-'0';
		st3.pop();
		D++;
	}
	for(int i=D;i>0;i++)
	{
		T+=k%(10^D);
	}
}
int main()
{
	freopen("and.in","r",stdout);
	freopen("and.out","w",stdout);
	int n,m,a[100005],b[10000010];
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=0;i<m;i++)
	{
		_and(turn1(a[i]),turn1(i+1));
	}
	cout << T;
}
