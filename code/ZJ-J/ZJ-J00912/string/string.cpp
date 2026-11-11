#include<bits/stdc++.h>
using namespace std;
long long n,a[200100],leftt,rightt,sum;
char c[200100];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	leftt=1;
	rightt=n;
	while(leftt<=rightt)
	{
		if(c[rightt]!=c[leftt])
		{
			sum+=min(a[leftt],a[rightt]);
		}
		if(a[leftt]>a[rightt])
		{
			a[leftt]-=a[rightt];
			rightt--;
		}
		else if(a[leftt]==a[rightt])
		{
			leftt++;
			rightt--;
		}
		else 
		{
			a[rightt]-=a[leftt];
			leftt++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
