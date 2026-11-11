#include<bits/stdc++.h>
using namespace std;
string g,b;
char c;
int n,j;
int a,cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int i=1;i<=a;i++)
		{
			g+=c;
			cnt++;
		}
	}
	for(int i=cnt;i>=0;i--)
	{
		b[j]=g[i];
		j++;
	}
	if(b==g)
	{
		cout<<0;
	}
	return 0;
}