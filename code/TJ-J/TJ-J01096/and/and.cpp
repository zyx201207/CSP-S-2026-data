#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[10005];
	int num[1005];
	int sum=0;
	int ans=1;
	if(m==1)
	{
		cout << 0;
	}
	for(int i=1;i<=n; i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n; i++)
	{
		for(int j=1+i;j<=n; j++)
		{
			sum=(a[i]&a[j]);
			num[ans]=sum;
			ans++;
		}
	}
	sort(num+1,num+ans+1);
	cout << num[ans];
	return 0;
}
