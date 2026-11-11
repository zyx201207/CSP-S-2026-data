#include<bits/stdc++.h>
using namespace std;
long long n,l,r,li,ri;
long long ans,sum;
long long a[200005];
char b[200005]; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> b[i];
		ans+=a[i];
	}
	l=0,r=ans+1,li=1,ri=n;
	if(ans%2==1)
	{
		ans=ans/2;
	}
	else
	{
		ans=ans/2;
	}
	
	while(1)
	{
		if(l>=ans||r<=ans||li==ri)
		{
			break;
		}
		long long c=a[li],d=a[ri];
		if(a[li]>=a[ri])
		{
			
			a[li]-=a[ri];
			if(b[li]!=b[ri])
			{
				sum+=a[ri];
			}
			ri--;
			r-=d;
			
			
		}
		else
		{
			a[ri]-=a[li];
			if(b[li]!=b[ri])
			{
				sum+=a[li];
			}
			li++;
			l+=c;
			
		}
	}
	cout << sum;
	return 0;
}
/*
3
2 a
2 b
1 c
*/
