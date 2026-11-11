#include<bits/stdc++.h>
using namespace std;
struct mod{
	long long number;
	char letter;
}a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%s",&a[i].number,&a[i].letter);
	}
	int l,r;
	l=1;r=n;
	long long cnt=0;
	while(l<r)
	{
		long long t=0;
		if(a[l].number<a[r].number)
		{
			t=a[l].number;
			a[r].number-=a[l].number;
			a[l].number=0;
		}
		else
		{
			t=a[r].number;
			a[l].number-=a[r].number;
			a[r].number=0;
		}
		if(a[l].letter!=a[r].letter)
		{
			cnt=cnt+t;
		}
		if(a[r].number==0)
		{
			r--;
		}
		if(a[l].number==0)
		{
			l++;
		}
	}
	printf("%d",cnt);
	return 0;
}