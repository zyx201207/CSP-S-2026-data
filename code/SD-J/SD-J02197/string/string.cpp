#include<bits/stdc++.h>
using namespace std;
string a,a1;
long long b=0,c=0,l,ans=0;
char d;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>b;
	for(int i=1;i<=b;i++)
	{
		cin>>c>>d;
		for(int j=1;j<=c;j++)
		a=a+d;
	}
	for(int i=a.size()-1;i>=0;i--)
	{
		a1=a1+a[i];
	}
	if(a1==a)
	{
		cout<<"0"<<endl;
		return 0;
	}
	if(a.size()%2==1)
	{
		l=a.size()/2+1;
		for(int i=0,j=a.size()-1;i<=l,j>=l;i++,j--)
		{
			if(a[i]!=a[j])
			ans++;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
