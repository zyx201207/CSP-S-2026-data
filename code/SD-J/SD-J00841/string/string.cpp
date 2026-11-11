#include<iostream> 
using namespace std;
struct aa
{
	int d;
	char c;
}a[200005],b[200005];
int main()
{
	//system("fc /w string.out string.out");
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].d>>a[i].c;
		b[i].d=a[i].d;
		b[i].c=a[i].c;
	}
	for(int i=1,j=n;i<=n&&j>=1;)
	{
		if(a[i].d>=b[j].d)
		{
			if(b[j].d==0)
			{
				j--;
			}
			else
			{
				if(a[i].c!=b[j].c)
				{
					cnt=cnt+b[j].d;
				}
				a[i].d=a[i].d-b[j].d;
				j--;
			}
		}
		else
		{
			if(a[i].d==0)
			{
				i++;
			}
			else
			{
				if(a[i].c!=b[j].c)
				{
					cnt=cnt+a[i].d;
				}
				b[j].d=b[j].d-a[i].d;
				i++;
			}
		}
	}
	cout<<cnt/2<<"\n";
	return 0;
}
