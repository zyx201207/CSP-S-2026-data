# include <bits/stdc++.h>
using namespace std;
long long a[100005];
char b[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,flag=0;
	long long sum2=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(i%2==0&&b[i%2]!=b[i%2+1])
		{
			b[i%2+1]=b[i%2];
			sum2++;
			flag=1;
		}	
		if(i%2==1&&b[i%2]!=b[i%2-1])
		{
			b[i%2+1]=b[i%2-1];
			sum2++;
			flag=1;
		}
		if(b[i]!=b[i+1]&&flag==0)
		{
			flag=1;
			b[i+1]=b[i];
			sum2+=a[i+1];
		}
	}
	cout<<sum2;
	if(flag==0)
	{
		cout<<"0";
	}
	return 0;
}
