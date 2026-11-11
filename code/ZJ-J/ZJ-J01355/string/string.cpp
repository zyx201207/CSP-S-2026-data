#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,dj,x;
char tot[MAXN];
struct a{
	char c;
	int w;
};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int s=1;
	a cnt[100005];
	for (int i=1;i<=n;i++)
	{
		cin>>cnt[i].w>>cnt[i].c;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=cnt[i].w;j++)
		{
			tot[s]=cnt[i].c;
			x++;
			s++;
		}
	}
	for (int i=1;i<=x/2;i++)
	{
		if (tot[i]!=tot[x-i+1]) dj++;
	}
	cout<<dj;
	return 0;
}
