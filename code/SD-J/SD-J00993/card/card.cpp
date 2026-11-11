#include<iostream>
#include<stack>
using namespace std;
int n,m;
int a[500100];
int la[500100];
int bi[500100];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		la[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int x=i;
		while(x<=n)
		{
			bi[a[x]]++;
			if(la[a[x]]!=x) x=la[a[x]];
			x++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << bi[i] << ' ';
	}
	return 0;
}
