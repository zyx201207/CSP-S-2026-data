#include<bits/stdc++.h>
using namespace std;
struct node{
	int num,re;
	string str;
};
node a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num;
		string stri="";
		int t=a[i].num;
		int s=0;
		while(t!=0)
		{
			if(t%2==1)
			{
				s++;
			}
			stri+=char(t%2+'0');
			t=t/2;
		}
		a[i].re=s;
		a[i].str=stri;
		cout<<a[i].re<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j].re<a[j+1].re)
			{
				swap(a[j],a[j+1]);
			}
			if(a[j].re==a[j+1].re&&a[j].str>a[j+1].str)
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	int sum=a[1].num;
		for(int i=2;i<=m;i++)
		{
			sum=sum & a[i].num;
		}
	cout<<sum;
	return 0;
}
