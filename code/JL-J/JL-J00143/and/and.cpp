#include<bits/stdc++.h>
using namespace std;
#define N 1000001
int a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long b,c,p=0,q=0;
	cin>>b>>c;
	for(int i=0;i<b;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<b;i++)
	{
		for(int j=q;j<q+c;j++)
		{
			if(j!=p+c-1)
			{
				if((a[i]&a[j])>=p)
					p=a[j]&a[j+1];
			}
		}
	}
	cout<<p<<endl;
	return 0;
}
