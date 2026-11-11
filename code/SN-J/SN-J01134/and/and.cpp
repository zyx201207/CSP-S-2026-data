#include<bits./stdc++.h>
using namespace std;
struct xx{
	long long ch;
	long long sh;
};
bool cmp(xx x,xx y)
{
	if(x.ch!=y.ch)
	{
		return x.ch>y.ch;
	}
	else
	{
		return x.sh>y.sh;
	}
}
xx a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		long long z;
		cin>>z;
		long long d=z;
		long long cnt=0;
		while(z!=0)
		{
			z=z>>1;
			if(z&1)
			{
				cnt++;
				
			}
		}
		a[i].ch=cnt;
		a[i].sh=d;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=m;i++)
	{
		a[i].sh=a[i].sh&a[i-1].sh;
	}
	cout<<a[m].sh;
	return 0;
 } 
