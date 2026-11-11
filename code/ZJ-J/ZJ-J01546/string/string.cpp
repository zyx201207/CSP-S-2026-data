#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
int n;
LL sum,x[N];
string a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i]>>a[i];
	int i=1,j=n;
	while(i<j)
	{
		int f=0;
		if(a[i]==a[j])
		{
			if(x[i]==x[j])i++,j--;
			else if(x[i]>x[j])
			{
				x[i]-=x[j];
				j--;
			}
			else
			{
				x[j]-=x[i];
				i++;
			}
		}
		else
		{
			if(x[i]==x[j])
			{
				sum+=x[i];
				i++,j--;
			}
			else if(x[i]>x[j])
			{
				sum+=x[j];
				x[i]-=x[j];
				j--;
			}
			else
			{
				sum+=x[i];
				x[j]-=x[i];
				i++;
			}
		}
	}
	cout<<sum;
	return 0;
}
