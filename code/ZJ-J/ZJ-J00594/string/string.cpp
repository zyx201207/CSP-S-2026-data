#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
char b[20000000000010];
long long n,cnt=1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		int d=a[i];
		for(int j=1;j<=d;j++)
		{
			b[cnt]=c[i];
			cnt++;
		}
	}
	long long left=1,right=cnt-1,sum=0;
	while(left<=right)
	{
		if(b[left]!=b[right])
		{
			sum++;
		}
		left++;
		right--;
	}
	cout<<sum;
	return 0;
}
