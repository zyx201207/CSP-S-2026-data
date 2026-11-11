#include<bits/stdc++.h>
using namespace std;
int n;
int a[20006];
char c[20006];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	if(n==1)
	{
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	bool flag=true;
	for(int i=1;i<n;i++)
	{
		if(c[i]!=c[i-1])
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(flag==0&&n==2)
	{
		cout<<min(a[0],a[1]);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	int left=0,right=n-1;
	long long cnt=0;
	for(;left<=right;)
	{
		if(c[left]!=c[right]) cnt+=min(a[left],a[right]);
		left++;
		right--;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
