#include<bits/stdc++.h>
using namespace std;
int a[25];
int main()
{
	freopen("travel.in",r,stdin)
	int c1,c2;
	char s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<1;
	else
		cout<<0;
	if(c1==c2&&s1==s2)
		cout<<1;
	else
		cout<<0;
	for(int i=1;i<=1;i++)
	{
		if(s1==s2&&a[i]==a[i]++)
		cout<<1;
		else
		cout<<0;
		if(s1==s2&&s2==s1++)
		cout<<1;
		else
		cout<<0;
	}
	freopen("travel.out",w,stdout)
}
