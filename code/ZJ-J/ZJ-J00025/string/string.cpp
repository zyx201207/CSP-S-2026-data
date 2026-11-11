#include<bits/stdc++.h>
using namespace std;
long long n,qly=0;
struct node
{
	long long x;
	char c;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].c;
	}
	long long i=1,j=n;
	while(i<=j)
	{
		if(a[i].c==a[j].c&&a[i].x==a[j].x)
		{
			i++;
			j--;
		}
		else if(a[i].c==a[j].c&&a[i].x>a[j].x)
		{
			j--;
			a[i].x-=a[j+1].x;
		}
		else if(a[i].c==a[j].c&&a[i].x<a[j].x)
		{
			i++;
			a[j].x-=a[i-1].x;
		}
		else if(a[i].c!=a[j].c&&a[i].x==a[j].x)
		{
			i++;
			j--;
			qly+=a[i-1].x;
		}
		else if(a[i].c!=a[j].c&&a[i].x>a[j].x)
		{
			qly+=a[j].x;
			a[i].x-=a[j].x;
			j--;
		}
		else if(a[i].c!=a[j].c&&a[i].x<a[j].x)
		{
			qly+=a[i].x;
			a[j].x-=a[i].x;
			i++;
		}
	}
	cout<<qly;
	return 0;
}