#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node
{
	int a;
	char c;
}a[201010];
int vis[1010100];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,as=0,bs=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].c;
	}
	int i=1,j=n;
	for(;i!=j;)
	{
		if(i>=j)
		{
			break;
		}
		if(a[i].c!=a[j].c)
		{
			sum+=abs(min(as+a[i].a,bs+a[j].a)-max(as,bs));
//			cout<<as<<" "<<as+a[i].a<<"   "<<bs<<" "<<bs+a[j].a<<"\n";
			if(as+a[i].a>bs+a[j].a)
			{
				bs+=a[j].a;
				j--;
			}
			else if(as+a[i].a<bs+a[j].a)
			{
				as+=a[i].a;
				i++;
			}
			else
			{
				as+=a[i].a;
				bs+=a[j].a;
				i++;
				j--;
			}
		}
		else
		{
			if(as+a[i].a>bs+a[j].a)
			{
				bs+=a[j].a;
				j--;
			}
			else if(as+a[i].a<bs+a[j].a)
			{
				as+=a[i].a;
				i++;
			}
			else
			{
				as+=a[i].a;
				bs+=a[j].a;
				i++;
				j--;
			}
		}
	}
	cout<<sum;
}