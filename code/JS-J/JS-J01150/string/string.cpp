#include<bits/stdc++.h>
using namespace std;
char a[200005];
long long res=0, sum=1, b[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin>>b[i]>>x;
		for(int j=sum;j<b[i]+sum;j++)
		{
			a[j]=x;
		}
		sum+=b[i];
	}
	if(n<=1) 
	{
		cout<<"0";
		return 0;
	}
	else if(n<=2)
	{
		if(a[1]==a[2])
		{
			cout<<"0";
			return 0;
		}
		else
		{
			cout<<min(b[1], b[2]);
			return 0;
		}
	}
	
	else 
	{
		int p=sum;
		for(int i=1;i<=p;i++)
		{
			if(a[i]!=a[p]) res++;
			p--;
		}
	}
	cout<<res<<endl;
	return 0;
}
