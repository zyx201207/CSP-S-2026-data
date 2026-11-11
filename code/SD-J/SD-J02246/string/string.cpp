#include<bits/stdc++.h>
using namespace std;
struct w{
	long long shu;
	char zi;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].shu>>a[i].zi;
	}
	long long all=0;
	int tou=1,wei=n;
	while(tou<=wei)
	{
		if(a[tou].zi!=a[wei].zi)
		{
			if(a[tou].shu>=a[wei].shu)
			{
				a[tou].shu-=a[wei].shu;
				all+=a[wei].shu;
				a[wei].shu=0;
			}
			else
			{
				a[wei].shu-=a[tou].shu;
				all+=a[tou].shu;
				a[tou].shu=0;
			}
		}
		else
		{
			if(a[tou].shu>=a[wei].shu)
			{
				a[tou].shu-=a[wei].shu;
				a[wei].shu=0;
			}
			else
			{
				a[wei].shu-=a[tou].shu;
				a[tou].shu=0;
			}
		}
		if(a[tou].shu==0)
		{
			tou++;
		}
		if(a[wei].shu==0)
		{
			wei--;
		}
	}
	cout<<all;
	return 0;
}
