#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200005],q=0;
	char b[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int w=1;
	for(int i=1;i<=n/2;i++)
	{
		if(b[i]!=b[n-i+w])
		{
			if(a[i]==a[n-i+w])
			{
				q+=a[n-i+w];
			}
			else if(a[i]>a[n-i+w])
			{
				q+=a[n-i+w];
				a[i]-=a[n-i+w];
				w--;
				i--;
			
			}
			else if(a[i]<a[n-i+w])
			{
				q+=a[n];
				a[n-i+w]-=a[i];
				w++;
			}
		}
	}
	cout<<q;
	return 0;
 } 
