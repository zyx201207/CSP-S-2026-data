#include<bits/stdc++.h>
using namespace std;
long long a[200002],n,ans;
char s[200002];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	for(int i=1,j=n,l=0;i<=j;)
	{
		if(s[i]==s[j])
		{
			if(a[i]>a[j])
			{
				a[i]-=a[j];
				j--;
			}
			else if(a[i]==a[j])
			{
				i++;
				j--;
			}
			else
			{
				a[j]-=a[i];
				i++;
			}
		}
		else
		{
			//cout<<i<<" "<<j<<" "<<a[i]<<" "<<a[j]<<endl;
			ans+=min(a[i],a[j]);
			if(a[i]>a[j])
			{
				//cout<<a[i]<<" "<<a[j]<<endl;
				a[i]-=a[j];
				j--;
			}
			else if(a[i]==a[j])
			{
				i++;
				j--;
			}
			else
			{
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}