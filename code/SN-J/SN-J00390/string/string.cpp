#include <bits/stdc++.h>
using namespace std;
char a[1000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x,ans;
	cin>>n;
	string s;
	if(n==1)
	{
		cout<<0;
	}
	if(n==2)
	{
		for(int i=1;i<=2;i++)
		{
			cin>>a[i];
			s+=a[i];
		}
		if(s[0]==s[1]){
			cout<<0;
		}
		else
		{
			cout<<1;
		}
	}
	return 0;
}