#include<iostream>
#include<string>
using namespace std;
int n,head,tail;
long long cnt;
struct nod{
	long long x;
	char s;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].s;
	}
	head=1;
	tail=n;
	while(tail>head)
	{
		if(a[head].s!=a[tail].s)
		{
			if(a[head].x>a[tail].x)
			{
				cnt+=a[tail].x;
				a[head].x-=a[tail].x;
				tail--;
			}
			else if(a[head].x==a[tail].x)
			{
				cnt+=a[head].x;
				head++;
				tail--;
			}
			else
			{
				cnt+=a[head].x;
				a[tail].x-=a[head].x;
				head++;
			}
		}
		else
		{
			if(a[head].x>a[tail].x)
			{
				a[head].x-=a[tail].x;
				tail--;
			}
			else if(a[head].x<a[tail].x)
			{
				a[tail].x-=a[head].x;
				head++;
			}
			else
			{
				head++;
				tail--;
			}
		}
		
	}
	cout<<cnt;
	return 0;
 } 
