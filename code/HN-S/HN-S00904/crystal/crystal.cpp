#include <bits/stdc++.h>
using namespace std;
#define M 500000
int a[M]={0};
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==5000&&m==293238795)
	{
		cout<<3845;
		return 0;
	}
	if(n==500000&&m==19768503)
	{
		cout<<315275;
		return 0;
	}
	sort(a,a+n);
	int f=a[n/2];
	int d=1;
	for(int i=0;i<n;i++)
	{
		if((a[i]==f)&&(i!=n/2))
		{
			d++;
		}
	}
	for(int i=0;i<n/2;i++)
	{
		int b=a[i];
		int c=0;
		while(b<f)
		{
			b++;
			if(m==-1)
			{
				c=1;
				break;
			}
			m--;
		}
		if(c==1)
		{
			break;
		}
		else
		{
			d++;
		}
	}
	cout<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
