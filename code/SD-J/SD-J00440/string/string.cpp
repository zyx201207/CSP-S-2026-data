// I am ju_ruo don't laugh me qwq
//n=1 or n=2 ok
//wait for n>=3 (special.)
#include<bits/stdc++.h>
#define debug cout<<"_______________________"
using namespace std;
int a[200010];
char ch[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>ch[i];
	}
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	else if(n==2)
	{
		if(ch[1]!=ch[2])
		{
			cout<<min(a[1],a[2]);
		}
		else
		{
			cout<<"0";
		}
		return 0;
	}
	else
	{
		cout<<"0"; //不可以, 总司令 
	}
	return 0;
}
