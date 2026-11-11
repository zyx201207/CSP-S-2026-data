#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int i,a,n,l;
	string x,t,y;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>x;
		while(a!=0)
		{
			t+=x;
			a--; 
		} 
	}
	l=t.size();
	y=t;
	reverse(t.begin(),t.end());
	int l1,l2;
	int s=0;
	if(t==y)
	{
		cout<<0;
		return 0;
	}
	else
	{
		l1=l/2;
		if(l%2==0)
		{
			l2=l1+1;
		}
		else
		{
			l2=l1+2;
		}
		for(i=0;i<l1;i++)
		{
			if(y[i]!=y[l-1-i])
			{
				s++;
			}
		}
	}
	cout<<s;
	return 0;
}
