#include<bits/stdc++.h> 
using namespace std;
long long a[100005],n,cnt,sum1,sum2,minn=LLONG_MAX;
char c[100005],b[100005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i]; 
	}
	for(int i=0;i<n/2;i++)
	{
		if(c[i]!=c[n-i-1]&&a[i]>a[n-i-1]&&c[i]!=c[n-i-2])
		{
			cnt+=max(a[i],a[n-i-1]);
		}
		else if(c[i]!=c[n-i-1]&&a[i]>a[n-i-1]&&c[i]==c[n-i-2])
		{
			cnt+=min(a[i],a[n-i-1]);
		}
		else if(c[i]==c[n-i-1]&&a[i]>a[n-i-1]&&c[i]!=c[n-i-2])
		{
			cnt+=a[i]-a[n-i-1];
		}
		else if(c[i]!=c[n-i-1]&&a[i]==a[n-i-1])
		{
			cnt+=a[i];
		}
	}
	cout<<cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
