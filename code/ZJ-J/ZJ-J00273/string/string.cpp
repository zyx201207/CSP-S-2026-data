#include<iostream>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0,cs=0;
	int a[200005];
	char c[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
    }
	char b[1000005];
	if(n==1)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
	    for(int j=1;j<=a[i];j++)
	    {
	    	ans++;
	    	b[ans]=c[i];
		}
	}
	long long aa=ans/2;
	for(int i=1;i<=aa;i++)
	{
		if(b[i]!=b[ans-i+1])
		{
			cs++;
		}
	}
	cout<<cs;
	return 0;
}
